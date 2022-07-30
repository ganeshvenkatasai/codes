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

void dfstraversal(vector<pair<int,int>> g[],int u,vector<bool> &visited){
	cout<<u<<" ";
	visited[u]=true;
	for(int i=0;i<g[u].size();i++){
		if(!visited[u]) dfstraversal(g,g[u][i].first,visited);
	}
}

void dfs(vector<pair<int,int>> g[],int V){
	vector<bool> visited(V,false);
	for(int u=0;u<V;u++){
		if(!visited[u]) dfstraversal(g,u,visited);
	}
}

int main(){
	int V=5;
	vector<pair<int,int>> g[V];
	addEdge(g,1,2,4);
	addEdge(g,1,3,5);
	addEdge(g,2,4,2);
	addEdge(g,0,3);
	display(g,V);
	dfs(g,V);
	
	return 0;
}
