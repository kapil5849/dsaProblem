#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(0);
    v.push_back(4);
    v.push_back(1);
    cout<<v.size()<<endl;
    cout<<v.empty()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    it=v.begin();
    v.erase(it);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.clear();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v.empty()<<endl;
    return 0;
}
