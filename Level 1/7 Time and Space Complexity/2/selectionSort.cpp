#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        int min = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr);
    cout<<"selection sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}