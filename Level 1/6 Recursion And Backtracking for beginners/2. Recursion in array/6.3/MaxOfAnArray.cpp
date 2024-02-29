#include<bits/stdc++.h>
using namespace std;
int maxOfArray(int arr[],int n,int i){
    if(i==n){
        return INT_MIN;
    }
    int rest = maxOfArray(arr,n,i+1);
    return max(rest,arr[i]);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxOfArray(arr,n,0);
    return 0;
}
