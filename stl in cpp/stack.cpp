#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    s.push(5);
    s.push(11);
    s.push(2);
    s.push(7);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.empty()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}