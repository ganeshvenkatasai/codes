// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int i,int j,int row,int col){
       int xarr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
       int yarr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
       
        for(int k=0;k<8;k++){
            int x=i+xarr[k],y=j+yarr[k];
            if(x>=0 && x<row && y>=0 && y<col && grid[x][y]=='1' && !visited[x][y]){
                visited[x][y]=true;
                dfs(grid,visited,x,y,row,col);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    visited[i][j]=true;
                    dfs(grid,visited,i,j,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
