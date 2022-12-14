// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int find(int in[],int val,int i,int j){
        for(int k=i;k<=j;k++) if(in[k]==val) return k;
    }
    
    Node* f(Node* root,int in[],int pre[],int &id,int i,int j){
        if(i>j) return NULL;
        int m=find(in,pre[id],i,j);
        root=new Node(pre[id]);
        id++;
        root->left=f(root,in,pre,id,i,m-1);
        root->right=f(root,in,pre,id,m+1,j);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root=NULL;
        int id=0,i=0,j=n-1;
        return f(root,in,pre,id,i,j);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
