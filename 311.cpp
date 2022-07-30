// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> l(n,-1),r(n,n);
        stack<int> s;
        for(int i=0;i<n;i++){
             if(s.empty()){
                s.push(i);
                continue;
            }
            else if(arr[i]>arr[s.top()]){
                l[i]=s.top();
                s.push(i);
            }
            else{
                while(!s.empty() && arr[i]<=arr[s.top()]){
                    s.pop();
                }
                if(!s.empty()) l[i]=s.top();
                s.push(i);
            }
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
                continue;
            }
            else if(arr[i]>arr[s.top()]){
                r[i]=s.top();
                s.push(i);
            }
            else{
                while(!s.empty() && arr[i]<=arr[s.top()]){
                    s.pop();
                }
                if(!s.empty()) r[i]=s.top();
                s.push(i);
            }
        }
        long long int ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long int k=(r[i]-l[i]-1)*arr[i];
            if(ans<k) ans=k;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
