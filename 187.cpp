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

void topView(Node *root){
	map<int,int> mp;
	queue<pair<Node *,int>> q;
	q.push({root,0});
	while(!q.empty()){
		Node *curr=q.front().first;
		int h=q.front().second;
		q.pop();
		if(curr->left) q.push({curr->left,h-1});
		if(curr->right) q.push({curr->right,h+1});
		mp[h]=curr->data;
	}
	for(auto x:mp) cout<<x.second<<" ";
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
	
	topView(root);
	return 0;
}
