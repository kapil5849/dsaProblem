#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    q.push(5);
    q.push(11);
    q.push(2);
    q.push(7);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
