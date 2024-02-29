#include<bits/stdc++.h>
using namespace std;
void pivot(vector<int> &arr,int p){
    int i=0;
    int j=0;
    while(i<arr.size()){
        if(arr[i]>p){
            i++;
        }else{
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int p;
    cin>>p;
    pivot(arr,p);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}