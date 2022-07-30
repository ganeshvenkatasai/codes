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



void traverse(Node *root,int &count){
	if(!root) return;
	count++;
	traverse(root->left,count);
	traverse(root->right,count);
}



void findMedian(Node *root,int count,int &track,int &ans1,int &ans2,Node * &prev){
	if(root){
		findMedian(root->left,count,track,ans1,ans2,prev);
		if(track==-1) track=1;
		else track++;
		if(track==count) {
		    ans1=root->data;
		    ans2=prev->data;
		    return;
		}
		prev=root;
		findMedian(root->right,count,track,ans1,ans2,prev);
	}
}
void median(Node *root){
	int count=0;
	Node *prev=NULL;
	traverse(root,count);
	int ans1=0,ans2=0,track=-1;
	findMedian(root,ceil(count/2)+1,track,ans1,ans2,prev);
	if(count%2==0) cout<<(ans1+ans2)/2;
	else cout<<ans1;
	
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
	
	median(root);

	return 0;
}
