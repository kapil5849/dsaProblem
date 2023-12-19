#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(j==m-1){
                dp[i][j]=arr[i][j];
            }
            else if(i==0){
                dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+arr[i][j];
            }
            else if(i==n-1){
                dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+arr[i][j];
            }
            else{
                dp[i][j]=max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]))+arr[i][j];
            }
        }
    }
    int maxGold = dp[0][0];
    for(int i=1;i<n;i++){
        maxGold=max(maxGold,dp[i][0]);
    }
    cout<<maxGold<<endl;
    return 0;
}


// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1