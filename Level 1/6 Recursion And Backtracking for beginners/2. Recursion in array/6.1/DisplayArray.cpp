#include<bits/stdc++.h>
using namespace std;
void displayArray(int arr[],int idx,int n){
    if(idx==n){
        return;
    }
    cout<<arr[idx]<<" "; // Expectation
    displayArray(arr,idx+1,n); // faith
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    displayArray(arr,0,n);
    return 0;
}
