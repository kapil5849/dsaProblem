#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int> &arr,int low, int high){
    int i = low;
    int j = low;
    int pi = arr[high];
    while(i<=high){
        if(arr[i]<=pi){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }else{
            i++;
        }
    }
    return j-1;
}
void quick(vector<int> &arr,int low,int high){
    if(low>=high){
        return;
    }
    int n= arr.size();
    int pi = pivot(arr,low,high);
    quick(arr,low,pi-1);
    quick(arr,pi+1,high);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    quick(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
