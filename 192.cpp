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

Node * f(string s,int &i){
	if(s.size()==0 || i>=s.size()) return NULL;
	int num=0;
	while(i<s.size() && s[i]!='(' && s[i]!=')'){
		num=num*10+(s[i]-'0');
		i++;
	}
	Node *root=NULL;
	if(num>0) root=new Node(num);
	if(i<s.size() && s[i]=='(') root->left=f(s,++i);
	if(i<s.size() && s[i]==')'){
		i++;
		return root;
	}
	if(i<s.size() && s[i]=='(') root->right=f(s,++i);
	if(i<s.size() && s[i]==')')	i++;
	return root;
}

int main(){
	
	string s="4(2(3)(1))(6(5))";
	int i=0;
	Node *root=f(s,i);
	preorderRecursion(root);

	return 0;
}
