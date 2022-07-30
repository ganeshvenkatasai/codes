#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int data;
		node* left;
		node* right;
		node(int val)
		{
			this->data=val;
			this->left=this->right=NULL;
		}
};
void inorder(node* root)
{
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void mirror(node* root)
{
	if(!root)return;
	mirror(root->left);
	mirror(root->right);
	swap(root->left,root->right);
}
int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	inorder(root);
	cout<<"\n";
	mirror(root);
	inorder(root);
	
	return 0;
	
}
