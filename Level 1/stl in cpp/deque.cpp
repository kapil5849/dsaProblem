#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(3);
    d.push_back(8);
    d.push_back(1);
    d.push_back(5);
    d.push_back(0);
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    d.push_front(10);
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    d.pop_back();
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    d.pop_front();
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    cout<<d.size()<<endl;
    cout<<d.empty()<<endl;
    deque<int>::iterator it;
    it=d.begin();
    d.erase(it);
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.clear();
    cout<<d.empty()<<endl;
    
    return 0;
}