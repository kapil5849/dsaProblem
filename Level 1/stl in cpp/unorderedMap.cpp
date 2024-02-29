#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int> um;
    um.insert(pair<string,int> ("English",45));
    um.insert(pair<string,int> ("Maths",48));
    um["science"]=50;
    um["history"]=41;
    cout<<um.empty()<<endl;
    cout<<um.size()<<endl;
    for(auto i:um){
        cout<<i.first<<"="<<i.second<<endl;
    }
    um.erase("science");
    for(auto i:um){
        cout<<i.first<<"="<<i.second<<endl;
    }
    if(um.find("Maths")!=um.end()){
        cout<<"present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }
    if(um.count("science")){
        cout<<"the key is present"<<endl;
    }else{
        cout<<"the key is not present"<<endl;
    }
    um.clear();
    cout<<um.empty()<<endl;
    cout<<um.size()<<endl;
    return 0;
}