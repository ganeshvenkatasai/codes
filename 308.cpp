#include<bits/stdc++.h>
using namespace std;

void f(stack<int> &s,queue<int> &q){
	if(s.empty()) return;
	q.push(s.top());
	s.pop();
	f(s,q);
	s.push(q.front());
	q.pop();
}

int main()
{
    stack<int> s;
    queue<int> q;
    s.push(1);
    s.push(2);
    s.push(3);
    f(s,q);
    while(!s.empty()){
    	cout<<s.top()<<" ";
    	s.pop();
	}
}
