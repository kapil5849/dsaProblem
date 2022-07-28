#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1;
    int arr1[n1];
    unordered_map<int,int> mpp;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
        mpp[arr1[i]]++;
    }
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
        if(mpp.find(arr2[i])!=mpp.end()){
            cout<<arr2[i]<<endl;
             mpp.erase(arr2[i]);    
        }
    }
    return 0;
}