#include<bits/stdc++.h>
using namespace std;
vector<string> getMazePath(int sr,int sc,int dr,int dc){
    if(sr==dr && sc==dc){
        vector<string> base;
        base.push_back("");
        return base;
    }
    else if(sr>dr or sc>dc){
        vector<string> base;
        return base;
    }
    vector<string> paths;
    for(int hms=1;hms<=dc;hms++){
        vector<string> hPath=getMazePath(sr,sc+hms,dr,dc);
        for(auto path:hPath){
            paths.push_back("h"+to_string(hms)+path);
        }
    }
    for(int vms=1;vms<=dr;vms++){
        vector<string> vPath=getMazePath(sr+vms,sc,dr,dc);
        for(auto path:vPath){
            paths.push_back("v"+to_string(vms)+path);
        }
    }
    for(int dms=1;dms<=dr && dms<=dc;dms++){
        vector<string> dPath=getMazePath(sr+dms,sc+dms,dr,dc);
        for(auto path:dPath){
            paths.push_back("d"+to_string(dms)+path);
        }
    }
    return paths;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> ans=getMazePath(1,1,n,m);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1){
            cout<<", ";
        }
    }
    cout<<"]";
    return 0;
}
