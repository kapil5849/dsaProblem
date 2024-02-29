#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
    insertionSort(arr);
    cout<<"insertion sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}