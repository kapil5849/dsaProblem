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
    int x;
    cin>>x;
    int i =0,j=n-1;
    while(i<n and j>=0){
        if(arr[i][j]==x){
            cout<<"answer : "<<i<<endl<<j;
            return 0;
        }
        else if(x<arr[i][j]){
            j--;
        }else{
            i++;
        }
    }
    cout<<"Not Found";
    return 0;
}
