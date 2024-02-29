#include<bits/stdc++.h>
using namespace std;  
void display(vector<vector<int>> arr){
    int i,j;
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n; 
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"answer: "<<endl;
    for(int gap = 0;gap<n;gap++){ 
        for(int i=0,j=gap;j<n;i++,j++){
            cout<<arr[i][j]<<endl;
        }
    }
    return 0;
}
