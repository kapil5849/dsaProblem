#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,m1,n2,m2;
    cin>>n1>>m1;
    vector<vector<int>> arr1(n1,vector<int>(m1));   
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cin>>arr1[i][j];
        }
    }
    cin>>n2>>m2;
    vector<vector<int>> arr2(n2,vector<int>(m2));
    for(int i=0;i<n2;i++){
        for(int j=0;j<m2;j++){
            cin>>arr2[i][j];
        }
    }
    if(m1!=n2){
        cout<<"Invalid input";
        return 0;
    }
    vector<vector<int>> ans(n1,vector<int>(m2));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            for(int k=0;k<m1;k++){
                ans[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }   
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}