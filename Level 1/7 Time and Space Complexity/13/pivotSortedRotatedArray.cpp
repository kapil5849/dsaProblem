#include<bits/stdc++.h>
using namespace std;
int pivotSortedRotatedArray(vector<int> &arr){
    int low = 0;
    int high = arr.size()-1;
    while(low<high){
        int mid = (low+high)/2;
        if(arr[mid]<arr[high]){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return arr[high];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<pivotSortedRotatedArray(arr);
    return 0;
}