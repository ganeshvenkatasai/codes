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
Node* suc(Node* root)
{
	
	while(root->left)
	{
		root=root->left;
	}
	return root;
}

Node *del(Node *root,int key){
	if(!root)return NULL;
	if(key<root->data)
	{
		root->left=del(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=del(root->right,key);
	}
	else
	{
		if(!root->left && !root->right)
		{
			return NULL;
		}
		else if(!root->left)
		{
			return root->right;
		}
		else if(!root->right)return root->left;
	
		
		  Node* temp=suc(root->right);
	       root->data=temp->data;
		   root->right=del(root->right,temp->data);
		}
	return root;
}

void inorder(Node* root)
{
	if(!root)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
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
	inorder(root);
	cout<<"\n";
	Node* temp=del(root,6);
	inorder(temp);

	
	return 0;
}
