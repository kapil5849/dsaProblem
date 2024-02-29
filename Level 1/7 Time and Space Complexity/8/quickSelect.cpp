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
int quickSelect(vector<int> &arr,int low,int high,int k){
    int pi = pivot(arr,low,high);
    if(k>pi){
        return quickSelect(arr,pi+1,high,k);
    }else if(k<pi){
        return quickSelect(arr,low,pi-1,k);
    }else{
        return arr[pi];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    int k;
    cin>>k;
    cout<<quickSelect(arr,0,n-1,k-1);
    return 0;
}