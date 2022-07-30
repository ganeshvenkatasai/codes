// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isValid(int x,int y,int n,vector<vector<bool>> &vis,vector<vector<int>> &m){
        if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==false && m[x][y]==1){
            return true;
        }
        return false;
    }
    
    void f(int x,int y,vector<vector<int>> &m, int n,string str,vector<string> &ans,vector<vector<bool>> &vis){
        if(x==n-1 && y==n-1){
            ans.push_back(str);
            return;
        }

    vis[x][y]=true;
    int xarr[]={1,0,0,-1};
    int yarr[]={0,-1,1,0};
    string s="DLRU";
    
    for(int i=0;i<4;i++){
        if(isValid(x+xarr[i],y+yarr[i],n,vis,m)){
            vis[x+xarr[i]][y+yarr[i]]=true;
            f(x+xarr[i],y+yarr[i],m,n,str+s[i],ans,vis);
            vis[x+xarr[i]][y+yarr[i]]=false;
            
        }
    }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
         if(m[0][0]) f(0,0,m,n,"",ans,vis);
         return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
