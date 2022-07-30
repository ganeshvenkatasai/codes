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

void preorder(Node *root){
	if(root){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void fillVector(Node *root,vector<Node *> &v){
	if(!root) return;
	fillVector(root->left,v);
	v.push_back(root);
	fillVector(root->right,v);
}

Node * balancedBST(vector<Node *> v,int s,int e){
	if(s>e) return NULL;
	int mid=(s+e)/2;
	Node *root=v[mid];
	root->left=balancedBST(v,s,mid-1);
	root->right=balancedBST(v,mid+1,e);
	return root;
}

Node * f(Node *root){
	vector<Node *> v;
	fillVector(root,v);
	return balancedBST(v,0,v.size()-1);
}

int main(){
	
	Node *root=new Node(8);
	root->left=new Node(3);
	root->right=new Node(10);
	root->left->left=new Node(1);
	root->left->right=new Node(6);
	root->left->right->left=new Node(4);
	root->left->right->right=new Node(7);
	root->right->right=new Node(14);
	root->right->right->left=new Node(13);
	
	preorder(root);
	cout<<"\n";
	root=f(root);
	preorder(root);

	return 0;
}






