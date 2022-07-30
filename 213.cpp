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
Node* head=NULL;
Node* prev=NULL;



bool f(Node* root,int val)
{
	if(root==NULL) return false;
    if(root->data==val) return true;
	if(root->data<val) f(root->right,val);
	if(root->data>val) f(root->left,val);
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
	
	cout<<f(root,15);

	return 0;
}
