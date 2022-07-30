class Solution {
public:
    
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

int bfs(vector<pair<int,int>> g[],int V){
	vector<bool> visited(V,false);
	int c=0;
	for(int u=0;u<V;u++){
		if(!visited[u]) {
		bfstraversal(g,u,visited);
		c++;	
		}
	}
	return c-1;
}
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<pair<int,int>> g[n];
        for(int i=0;i<connections.size();i++){
            addEdge(g,connections[i][0],connections[i][1]);
        }
      return bfs(g,n);
    }
};







