#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    int low = 0;
    int high = n-1;
    int ceil = -1;
    int floor = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(data>arr[mid]){
            low = mid+1;
            floor = arr[mid];
        }
        else if(data<arr[mid]){
            high = mid-1;
            ceil = arr[mid];
        }
        else{
            ceil = arr[mid];
            floor = arr[mid];
            break;
        }
    }
    cout<<"ceil value :"<<ceil<<endl;
    cout<<"floor value :"<<floor<<endl;
    return 0;
}
