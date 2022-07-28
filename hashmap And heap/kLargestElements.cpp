#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr,int k){
    priority_queue<int,vector<int>,greater<int>> pqm; // min_heap...
    for(int i=0;i<k;i++){
        pqm.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        if(arr[i]>pqm.top()){
            pqm.pop();
            pqm.push(arr[i]);
        }
    }
    while(pqm.size()>0){
        cout<<pqm.top()<<" ";
        pqm.pop();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    int k;
    cin>>k;
    solve(arr,k);
    return 0;
}