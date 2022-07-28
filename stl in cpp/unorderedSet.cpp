#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> us;
    us.insert(5);
    us.insert(11);
    us.insert(2);
    us.insert(7);
    cout<<us.empty()<<endl;
    cout<<"size: "<<us.size()<<endl;
    for(auto i:us){
        cout<<i<<" ";
    }
    cout<<endl;
    us.erase(5);
    for(auto i:us){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<us.size()<<endl;
    if(us.find(5)!=us.end()){
        cout<<"present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }
    us.clear();
    cout<<us.empty()<<endl;
    return 0;
}