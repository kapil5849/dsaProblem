#include<bits/stdc++.h>
using namespace std;
int LastIndex(int a[],int n,int x,int idx){
    if(idx==n){
        return -1;
    }
    int liisa = LastIndex(a,n,x,idx+1); 
    if(a[idx]==x or liisa!=-1){
        return max(liisa,idx);
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    cout<<LastIndex(a,n,x,0);
    return 0;
}