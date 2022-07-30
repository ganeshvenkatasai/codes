#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int arr[]={3,4,8,5,7,2,6,1,9};
    int nse[]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
    for(int i=8;i>=0;i--){
    	if(s.empty()){
    		s.push(arr[i]);
    		continue;
		}
		else if(s.top()<arr[i]){
			nse[i]=s.top();
			s.push(arr[i]);
		}
		else if(s.top()>arr[i]){
			while(!s.empty() && s.top()>=arr[i]){
				s.pop();
			}
			if(!s.empty()) nse[i]=s.top();
			s.push(arr[i]);
		}	
	}
	for(int i=0;i<9;i++) cout<<arr[i]<<" ";
	cout<<"\n";
	for(int i=0;i<9;i++) cout<<nse[i]<<" ";
	return 0;
}
