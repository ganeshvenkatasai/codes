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

void inorder(Node *root,Node * &prev){
	if(!root) return;
	inorder(root->left,prev);
	prev->right=root;
	prev=root;
	inorder(root->right,prev);
	
}

void f(Node *root){
	
	Node *dummy=new Node(-1);
	Node *prev=dummy;
	inorder(root,prev);
	Node *ret=dummy->right;
	delete dummy;
	while(ret) {
		cout<<ret->data<<" ";
		ret=ret->right;
	}
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
	
	f(root);

	return 0;
}
