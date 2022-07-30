#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void leftTraversal(Node * root){
	if(!root) return;
	if(root->left) { 
	   cout<<root->data<<" ";
	   leftTraversal(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
	   leftTraversal(root->right);
	}
}

void bottomTraversal(Node * root){
	if(!root) return;
	if(!root->left && !root->right) cout<<root->data<<" ";;
	bottomTraversal(root->left);
	bottomTraversal(root->right);	
}

void rightTraversal(Node * root){
	if(!root) return;
	if(root->right) { 
	   rightTraversal(root->right);
	   cout<<root->data<<" ";
	}
	else if(root->left){
	   rightTraversal(root->left);
	   cout<<root->data<<" ";
	}
}


void boundary(Node * root){
	leftTraversal(root);
	bottomTraversal(root);
	rightTraversal(root->right);
}


int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->right->left = newNode(9);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	
	boundary(root);

	

	return 0;
}

