#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lsf = INT_MAX;
    int tp = 0;
    int op =0;
    for(int i=0;i<n;i++){
        if(arr[i]<lsf){
            lsf=arr[i];
        }
        tp=arr[i]-lsf;
        if(tp>op){
            op=tp;
        }
    }
    cout<<op<<endl;
    return 0;
}