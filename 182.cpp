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

void preorderRecursion(Node *root){
	if(root){
		cout<<root->data<<" ";
		preorderRecursion(root->left);
		preorderRecursion(root->right);
	}
}

void preorderIteration(Node *root){
	Node *curr=root;
	stack<Node *> s;
    vector<int> res;
    if(!root) return;
    s.push(curr);
    while(!s.empty()){
    	Node *x=s.top();
    	s.pop();
    	res.push_back(x->data);
    	if(x->right) s.push(x->right);
    	if(x->left) s.push(x->left);
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
	
	preorderRecursion(root);
	cout<<"\n";
	preorderIteration(root);
	return 0;
}
