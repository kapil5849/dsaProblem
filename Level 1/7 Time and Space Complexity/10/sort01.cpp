#include<bits/stdc++.h>
using namespace std;
void sort01(vector<int> &arr){
    int i=0;
    int j=0;
    while(i<arr.size()){
        if(arr[i]==1){
            i++;
        }
        else{
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
    sort01(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}