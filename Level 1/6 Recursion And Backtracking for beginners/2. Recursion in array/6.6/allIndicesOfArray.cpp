#include<bits/stdc++.h>
using namespace std;
vector<int> allIndices(int a[],int n,int x,int idx,int fsf){
    if(idx==n){
        vector<int> temp(fsf);
        return temp;
    }
    vector<int> temp;
    if(a[idx]==x){
        temp = allIndices(a,n,x,idx+1,fsf+1);
        temp[fsf]=idx;
    }
    else{
        temp = allIndices(a,n,x,idx+1,fsf);
    }
    return temp;
}
int main(){
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    vector<int> ans = allIndices(a,n,x,0,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
