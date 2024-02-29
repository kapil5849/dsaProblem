#include<bits/stdc++.h>
using namespace std;
int FirstIndex(int a[],int n,int x,int i){
    if(i==n){
        return -1;
    }
    if(a[i]==x){
        return i;
    }
    else{
        return FirstIndex(a,n,x,i+1);
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
    cout<<FirstIndex(a,n,x,0)<<endl;
    return 0;
}
