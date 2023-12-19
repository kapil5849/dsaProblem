#include<bits/stdc++.h>
using namespace std;
vector<string> getStairPaths(int n){
    if(n==0){
        vector<string> base;
        base.push_back("");
        return base;
    }
    else if(n<0){
        vector<string> base;
        return base;
    }
    vector<string> paths;
    vector<string> path1 = getStairPaths(n-1);
    vector<string> path2 = getStairPaths(n-2);
    vector<string> path3 = getStairPaths(n-3);
    for(auto path:path1){
        paths.push_back("1"+path);
    }
    for(auto path:path2){
        paths.push_back("2"+path);
    }
    for(auto path:path3){
        paths.push_back("3"+path);
    }
    return paths;
}
int main(){
    int n;
    cin>>n;
    vector<string> ans = getStairPaths(n);
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
