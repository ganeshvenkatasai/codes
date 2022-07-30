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

vector <vector <int>> result;

void zigzag(Node* root){
	if(!root) return;
	queue<Node *> q;
	q.push(root);
    int f=0;
	while(!q.empty()){
		int sz=q.size();
		vector<int> level;
		while(sz--){
			Node * x=q.front();
			q.pop();
				if(x->left) q.push(x->left);
				if(x->right) q.push(x->right);
				level.push_back(x->data);
		}
		if(f) reverse(level.begin(),level.end());
		f=~f;
		result.push_back(level);
	}
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
	
	zigzag(root);

	for(int i=0 ; i<result.size() ; i++)
	{
		for(int j=0 ; j<result[i].size() ; j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}

