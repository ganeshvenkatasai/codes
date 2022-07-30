#include<bits/stdc++.h>
using namespace std;

void push(deque<int> &q,int x){
	q.push_front(x);
}

int pop(deque<int> &q){
	int x=q.front();
	q.pop_front();
	return x;
}

int main()
{
    deque<int> q;
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    cout<<pop(q)<" ";
    cout<<pop(q);
}
