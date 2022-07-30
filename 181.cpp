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

void inorderRecursion(Node *root){
	if(root){
		inorderRecursion(root->left);
		cout<<root->data<<" ";
		inorderRecursion(root->right);
	}
}

void inorderIteration(Node *root){
	if(!root) return;
	stack<Node *> s;
	vector<int>res;
	Node *curr=root;
	while(1){
		if(curr!=NULL){
			s.push(curr);
			curr=curr->left;
		}
		else{
			if(s.empty()) break;
			curr=s.top();
			s.pop();
			res.push_back(curr->data);
			curr=curr->right;
		}
	}
	 for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
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
	
	inorderRecursion(root);
	cout<<"\n";
	inorderIteration(root);
	return 0;
}
