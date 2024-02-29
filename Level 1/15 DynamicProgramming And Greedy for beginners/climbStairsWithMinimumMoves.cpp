#include<bits/stdc++.h>
using namespace std;
// int cs(vector<int> arr,int n,vector<int> &dp){
//     for(int i=n;i>=0;i--){
//         if(i==n){
//             dp[i]=0;
//             continue;
//         }
//         int minStep = 30;
//         for(int j=1;j<=arr[i] and (i+j)<=n;j++){
//             int value = 1+dp[i+j];
//             minStep=min(minStep,value);
//         }
//         dp[i]=minStep;
//     }
//     return dp[0];
// }
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,0);
    // cout<<cs(arr,n,dp)<<endl;
    for(int i=n;i>=0;i--){
        if(i==n){
            dp[i]=0;
            continue;
        }
        int minStep = 30;
        for(int j=1;j<=arr[i] and (i+j)<=n;j++){
            minStep=min(minStep,dp[i+j]);
        }
        dp[i]=1+minStep;
    }
    cout<<dp[0]<<endl;
    return 0;
}


// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0