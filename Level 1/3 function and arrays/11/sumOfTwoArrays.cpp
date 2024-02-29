#include<iostream>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int n = max(n1,n2);
    int arr3[n];
    int c = 0;
    int i = n1-1;
    int j= n2-1;
    int k = n-1;
    while(k>=0){
        int sum = c;
        if(i>=0){
            sum+=arr1[i];
        }
        if(j>=0){
            sum+=arr2[j];
        }
        c = sum/10;
        arr3[k] = sum%10;
        i--;
        j--;
        k--;
    }
    cout<<"ans"<<endl;
    if(c!=0){
        cout<<c<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<arr3[i]<<endl;
    }
    return 0;
}
