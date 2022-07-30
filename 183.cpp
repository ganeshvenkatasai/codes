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

void postorderRecursion(Node *root){
	if(root){
		postorderRecursion(root->left);
		postorderRecursion(root->right);
		cout<<root->data<<" ";
	}
}

void postorderIteration(Node *root){
	
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
	
	postorderRecursion(root);
	cout<<"\n";
	postorderIteration(root);
	return 0;
}
