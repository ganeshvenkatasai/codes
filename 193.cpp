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

void bt2dll(Node* root,Node* &head,Node* &prev){
	if(!root) return;
	bt2dll(root->left,head,prev);
	if(!head) head=root;
	if(prev){
		prev->right=root;
		root->left=prev;
	}
	prev=root;
	bt2dll(root->right,head,prev);
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	
	Node* head=NULL;
    Node* prev=NULL;
	bt2dll(root,head,prev);
    while(head){
    	cout<<head->data<<" ";
    	head=head->right;
	}
	

	return 0;
}

