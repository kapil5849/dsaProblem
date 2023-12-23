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
    for(int i=0;i<n;i++){
        int svj = 0;
        for(int j=1;j<n;j++){
            if(arr[i][j]<arr[i][svj]){
                svj=j;
            }
        }
        bool flag = true;
        for(int k=0;k<n;k++){
            if(arr[k][svj]>arr[i][svj]){
                flag=0;
                break;
            }
        }
        if(flag==true){
            cout<<"answer: "<<arr[i][svj];
            return 0;
        }
    }
    cout<<"Invalid input";
    return 0;
}
