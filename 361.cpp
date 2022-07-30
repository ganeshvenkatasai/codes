#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x,int y,int N){
	if(x>=1 && x<=N && y>=1 && y<=N) return true;
	return false;
}
int f(int x,int y,int end_x,int end_y,int N,int d,vector<vector<int>> &vis){
	if(is_valid(x,y,N) && vis[x][y]!=1){
		vis[x][y]=1;
		if(x==end_x && y==end_y) {
			return true;
		}
		else{
			if(f(x-2,y+1,end_x,end_y,N,d+1,vis)) return true;
			if(f(x-1,y+2,end_x,end_y,N,d+1,vis)) return true;
			if(f(x+1,y+2,end_x,end_y,N,d+1,vis)) return true;
			if(f(x+2,y+1,end_x,end_y,N,d+1,vis)) return true;
			if(f(x+2,y-1,end_x,end_y,N,d+1,vis)) return true;
			if(f(x+1,y-2,end_x,end_y,N,d+1,vis)) return true;
			if(f(x-1,y-2,end_x,end_y,N,d+1,vis)) return true;
			if(f(x-2,y-1,end_x,end_y,N,d+1,vis)) return true;
		}
	}

	return false;
}

int main(){
	int N=6;
	int x=4,y=5,end_x=1,end_y=1;
	vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	cout<<f(x,y,end_x,end_y,N,0,vis);
	
	return 0;
}
