#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
     int data;
     Node *left,*right;
     
      Node(int x){
     	data=x;
     	left=right=NULL;
	 }
};

void inorder(Node *root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void fillVector(Node *root,vector<int> &v){
	if(!root) return;
	fillVector(root->left,v);
	v.push_back(root->data);
	fillVector(root->right,v);
}

Node * balancedBST(vector<int> v,int s,int e,Node *root){
	if(s>e) return NULL;
	int mid=(s+e)/2;
	root->data=v[mid];
	root->left=balancedBST(v,s,mid-1,root);
	root->right=balancedBST(v,mid+1,e,root);
	return root;
}



vector<int> f(Node *root1,Node *root2){
	vector<int> v1,v2,v;
	fillVector(root1,v1);
	fillVector(root2,v2);
	int i=0,j=0;
	while(i<v1.size() && j<v2.size()){
		if(v1[i]>v2[j]) {
			v.push_back(v2[j]);
			j++;
		}
		else{
			v.push_back(v1[i]);
			i++;
		}
	}
	while(i<v1.size()){
		v.push_back(v1[i]);
		i++;
	}
	while(j<v2.size()){
		v.push_back(v2[j]);
			j++;
	}
	
	return v;
}

int main(){
	
	Node *root1=new Node(8);
	root1->left=new Node(3);
	root1->right=new Node(10);
	root1->left->left=new Node(1);
	root1->left->right=new Node(6);
	root1->left->right->left=new Node(4);
	root1->left->right->right=new Node(7);
	root1->right->right=new Node(14);
	root1->right->right->left=new Node(13);
	
	Node *root2=new Node(2);
	root2->left=new Node(46);
	root2->right=new Node(11);
	root2->left->left=new Node(19);
	root2->left->right=new Node(9);
	root2->left->right->left=new Node(45);
	root2->left->right->right=new Node(5);
	root2->right->right=new Node(1);
	root2->right->right->left=new Node(16);
	
	Node *root=NULL;
	inorder(root1);
	cout<<"\n";
	inorder(root2);
	cout<<"\n";
	vector<int> v=f(root1,root2);
	root=balancedBST(v,0,v.size()-1,root);
	inorder(root);

	return 0;
}






