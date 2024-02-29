#include<bits/stdc++.h>
using namespace std;
int main(){
    // max heap
    priority_queue<int> p;
    p.push(5);
    p.push(11);
    p.push(2);
    p.push(7);
    cout<<p.size()<<endl;
    cout<<p.top()<<endl;
    p.pop();
    cout<<p.empty()<<endl;
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    // min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(5);
    pq.push(11);
    pq.push(2);
    pq.push(7);
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.empty()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
