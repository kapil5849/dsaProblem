#include<bits/stdc++.h>
using namespace std;
vector<string> getMazePath(int sr,int sc,int dr, int dc){
    if(sr==dr and sc==dc){
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> hPath;
    vector<string> vPath;
    if(sc<dc){
        hPath=getMazePath(sr,sc+1,dr,dc);
    }
    if(sr<dr){
        vPath=getMazePath(sr+1,sc,dr,dc);
    }
    vector<string> paths;
    for(auto path:hPath){
        paths.push_back("h"+path);
    }
    for(auto path:vPath){
        paths.push_back("v"+path);
    }
    return paths;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> ans = getMazePath(1,1,n,m);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1){
            cout<<", ";
        }
    }
    cout<<"]";
    return 0;
}
