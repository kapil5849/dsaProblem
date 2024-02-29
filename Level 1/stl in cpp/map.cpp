#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> m;
    m.insert(pair<string,int>("english",45));
    m.insert(pair<string,int>("maths",48));
    m["science"]=50;
    m["history"]=41;
    m.erase("science");
    cout<<m.size()<<endl;
    cout<<m.empty()<<endl;
    for(auto i:m){
        cout<<i.first<<"="<<i.second<<endl;
    }
    if(m.find("hindi")!=m.end()){
        cout<<"available"<<endl;
    }else{
        cout<<"not available"<<endl;
    }
    if(m.count("hindi")){
        cout<<"the key is present"<<endl;
    }else{
        cout<<"the key is not present"<<endl;
    }
    m.clear();
    cout<<m.empty()<<endl;
    return 0;
}