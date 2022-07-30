#include <bits/stdc++.h>
using namespace std;

void minTime(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    vector<int> ans(V,1);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        for(auto it:adj[x]){
	            indegree[it]--;
	            if(indegree[it]==0){
	            	ans[it]=ans[x]+1;
	                q.push(it);
	            }
	        }
	    }
	    for(auto it:ans) cout<<it<<" ";
	}


void addEdge(vector<int> g[],int u,int v){
	g[u].push_back(v);
}

int main() {


    int V=10;
	vector<int> g[V+1];
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,0,4);
	addEdge(g,1,2);
	addEdge(g,1,8);
	addEdge(g,2,5);	
	addEdge(g,3,5);
	addEdge(g,3,7);
	addEdge(g,4,7);
	addEdge(g,5,6);
	addEdge(g,6,7);
	addEdge(g,7,9);	
    minTime(V,g);
    
    return 0;
}  
