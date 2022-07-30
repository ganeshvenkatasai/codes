#include<bits/stdc++.h>
using namespace std;

void f(stack<int> &s,int &i){
    if(s.size()<=i) return;

    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();
    if(a>b) swap(a,b);
    s.push(a);
    f(s,i);
    s.push(b);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(4);
    for(int i=1;i<s.size();i++){
        f(s,i);
    }
    while(!s.empty()){
    	cout<<s.top()<<" ";
    	s.pop();
	}
}
