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


int inorderPredecessor(Node *root){
	if(!root) return -1;
    if(root->right==NULL) return root->data;
    inorderPredecessor(root->right);
}

int inorderSuccessor(Node *root){
	if(!root) return -1;
    if(root->left==NULL) return root->data;
    inorderSuccessor(root->left);
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
	
	cout<<inorderPredecessor(root->left);
	cout<<" ";
	cout<<inorderSuccessor(root->right);
	
	return 0;
}
