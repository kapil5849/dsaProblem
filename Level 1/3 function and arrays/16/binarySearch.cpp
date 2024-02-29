#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int key){
    int l = 0;
    int h = size-1;
    while(l<=h){
        int m = (l+h)/2;
        if(key<arr[m]){
            h = m-1;
        }else if(key>arr[m]){
            l=m+1;
        }else{
            return m;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr,n,key);
    return 0;
}
