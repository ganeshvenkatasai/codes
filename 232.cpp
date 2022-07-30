// { Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */



void traverse(Node *root,unordered_set<int> &leafs,unordered_set<int> &nodes){
    if(!root) return;
    nodes.insert(root->data);
    if(!root->left && !root->right){
         leafs.insert(root->data);
         return;
    }
    traverse(root->left,leafs,nodes);
    traverse(root->right,leafs,nodes);
    
}

bool isDeadEnd(Node *root)
{
    if (root == NULL) return false;
    unordered_set<int> leafs,nodes;
    nodes.insert(0);
    traverse(root,leafs,nodes);
    for(auto i=leafs.begin();i!=leafs.end();i++){
        int x=(*i);
        if(nodes.find(x-1)!=nodes.end() && nodes.find(x+1)!=nodes.end()) return true;
    }
    return false;
    
}
