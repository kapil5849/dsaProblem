#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int mr = 0;
    int mc = 0;
    int mxr = n-1;
    int mxc = m-1;
    int tne = n*m;
    int cnt = 0;
    cout<<"ans: "<<endl;
    while(cnt<tne){
        // lw
        for(int i=mr,j=mc;i<=mxr and cnt<tne;i++){
            cout<<arr[i][mc]<<endl;
            cnt++;
        }
        mc++;
        // bw 
        for(int i=mxr,j=mc;j<=mxc and cnt<tne;j++){
            cout<<arr[mxr][j]<<endl;
            cnt++;
        }
        mxr--;
        // rw
        for(int i=mxr,j=mxc;i>=mr and cnt<tne;i--){
            cout<<arr[i][mxc]<<endl;
            cnt++;
        }
        mxc--;
        // tw
        for(int i=mr,j=mxc;j>=mc and cnt<tne;j--){
            cout<<arr[mr][j]<<endl;
            cnt++;
        }
        mr++;
    }
    return 0;
}