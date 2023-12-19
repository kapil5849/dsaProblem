#include<bits/stdc++.h>
using namespace std;
void sortK(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pqm;
    for(int i=0;i<=k;i++){
        pqm.push(arr[i]);
    }
    for(int i=k+1;i<n;i++){
        cout<<pqm.top()<<" ";
        pqm.pop();
        pqm.push(arr[i]);
    }
    while(pqm.size()>0){
        cout<<pqm.top()<<" ";
        pqm.pop();
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    int k;
    cin>>k;
    sortK(arr,n,k);
    return 0;
}
