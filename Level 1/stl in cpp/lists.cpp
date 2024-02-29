#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> l;
    l.push_back(5);
    l.push_back(11);
    l.push_back(2);
    l.push_front(7);
    l.push_front(14);
    cout<<l.size()<<endl;
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.pop_back();
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.pop_front();
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<l.empty()<<endl;
    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
    list<int>::iterator it;
    it=l.begin();
    l.erase(it);
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.clear();
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<l.empty()<<endl;
    return 0;
}