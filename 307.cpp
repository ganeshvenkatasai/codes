#include<bits/stdc++.h>
using namespace std;

void f(stack<int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int k=s.top();
	s.pop();
	f(s,x);
	s.push(k);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    f(s,0);
    while(!s.empty()){
    	cout<<s.top()<<" ";
    	s.pop();
	}
}
