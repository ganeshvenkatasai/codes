#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> g[],int u,int v,int w=1){
	g[u].push_back(make_pair(v,w));
	g[v].push_back(make_pair(u,w));
}

void display(vector<pair<int,int>> g[],int V){
	for(int i=0;i<V;i++){
		for(int j=0;j<g[i].size();j++){
			cout<<i<<" to "<<g[i][j].first<<" weight is : "<<g[i][j].second<<"\n";
		}
	}
}

void bfstraversal(vector<pair<int,int>> g[],int u,vector<bool> &visited){
      queue<int> q;
      q.push(u);
      visited[u]=true;
      while(!q.empty()){
      	int x=q.front();
      	q.pop();
      	cout<<x<<" ";
      	for(auto it:g[x]){
      		if(!visited[it.first]) {
      			visited[it.first]=true;
      			q.push(it.first);
			  }
		  }
	  }
}

void bfs(vector<pair<int,int>> g[],int V){
	vector<bool> visited(V,false);
	for(int u=0;u<V;u++){
		if(!visited[u]) bfstraversal(g,u,visited);
	}
}

int main(){
	int V=10;
	vector<pair<int,int>> g[V];
	addEdge(g,1,2,4);
	addEdge(g,1,3,5);
	addEdge(g,2,4,2);
	addEdge(g,0,3);
	addEdge(g,7,8,5);
	addEdge(g,8,9);	
	display(g,V);
	bfs(g,V);
	
	return 0;
}
