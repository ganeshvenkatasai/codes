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

void rightView(Node *root){
	queue<Node *> q;
	vector<int> res;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		res.push_back(q.front()->data);
		while(sz--){
			Node *x=q.front();
			q.pop();
			if(x->right) q.push(x->right);
			if(x->left) q.push(x->left);
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
	
	rightView(root);
	return 0;
}
