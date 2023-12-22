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
    int diff[n2];
    int i = n1-1;
    int j = n2-1;
    int k = n2-1;
    int c = 0;
    while(k>=0){
        int a1v = i>=0?arr1[i]:0;
        if(arr2[j]+c>=a1v){
            diff[k] = arr2[j]+c-a1v;
            c=0;
        }else{
            diff[k] = arr2[j]+c+10-a1v;
            c=-1;
        }
        i--;
        j--;
        k--;
    }
    int idx = 0;
    while(idx<n2){
        if(diff[idx]==0){
            idx++;
        }else{
            break;
        }
    }
    cout<<"ans: "<<endl;
    while(idx<n2){
        cout<<diff[idx]<<endl;
        idx++;
    }
    return 0;
}
