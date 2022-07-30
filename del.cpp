#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]=='1' && s[i+1]=='1'){
            cout<<2<<"\n";
            return;
        }
        else if(s[i]=='1' || s[i+1]=='1'){
            cout<<1<<"\n";
            return;
        }
    }
    cout<<0<<"\n";
    
}

int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

