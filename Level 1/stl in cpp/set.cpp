#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(5);
    s.insert(11);
    s.insert(2);
    s.insert(7);
    s.erase(5);
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    if(s.find(2)!=s.end()){
        cout<<"element is present in the set"<<endl;
    }else{
        cout<<"element is not found"<<endl;
    }
    s.clear();
    cout<<s.empty()<<endl;
    set<int,greater<int>> ss;
    ss.insert(5);
    ss.insert(11);
    ss.insert(2);
    ss.insert(7);
    cout<<ss.size()<<endl;
    cout<<ss.empty()<<endl;
    for(auto i:ss){
        cout<<i<<" ";
    }
    cout<<endl;
    ss.clear();
    cout<<ss.empty()<<endl;
    return 0;
}