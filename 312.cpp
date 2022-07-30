// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
 int findMaxLen(string s) {
        int i,n=s.size(),l1=0,r1=0,l2=0,r2=0,c1=0,c2=0,m1=0,m2=0;
        for(i=0;i<n;i++)
        {
            s[i]=='('?l1++:r1++;
            s[n-i-1]==')'?r2++:l2++;
            r1>l1?l1=r1=0:0;
            l2>r2?l2=r2=0:0;
            r1==l1?c1=l1:0;
            r2==l2?c2=l2:0;
            m1=max(m1,c1*2);
            m2=max(m2,c2*2);
        }
        return max(m1,m2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
