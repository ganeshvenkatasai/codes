#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> g[],int u,int v,int w=1){
	g[u].push_back(make_pair(v,w));
	g[v].push_back(make_pair(u,w));
}

void shortestPath(vector<pair<int,int> > adj[], int V, int src)
{   int INF=INT_MAX;
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main(){
	int V=9;
	vector<pair<int,int>> g[V];
	addEdge(g, 0, 1, 4);
    addEdge(g, 0, 7, 8);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 7, 11);
    addEdge(g, 2, 3, 7);
    addEdge(g, 2, 8, 2);
    addEdge(g, 2, 5, 4);
    addEdge(g, 3, 4, 9);
    addEdge(g, 3, 5, 14);
    addEdge(g, 4, 5, 10);
    addEdge(g, 5, 6, 2);
    addEdge(g, 6, 7, 1);
    addEdge(g, 6, 8, 6);
    addEdge(g, 7, 8, 7);
 
    shortestPath(g,V,0);
	
	return 0;
}
