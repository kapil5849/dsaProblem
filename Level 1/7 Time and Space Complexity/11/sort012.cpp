#include<bits/stdc++.h>
using namespace std;
void sort012(vector<int> &arr){
    int i=0;
    int j=0;
    int k=arr.size()-1;
    while(i<=k){
        if(arr[i]==0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }else if(arr[i]==1){
            i++;
        }else{
            swap(arr[i],arr[k]);
            k--;
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
    sort012(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}