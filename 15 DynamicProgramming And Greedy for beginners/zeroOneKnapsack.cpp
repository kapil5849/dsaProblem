#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> value(n,0);
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    vector<int> weight(n,0);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int cap;
    cin>>cap;
    vector<vector<int>> dp(n+1,vector<int>(cap+1));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(j>=weight[i-1]){
                int rCap = j - weight[i-1];
                if(dp[i-1][rCap]+value[i-1]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][rCap]+value[i-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][cap]<<endl;
    return 0;
}

// 5

// 15
// 14
// 10
// 45
// 30

// 2
// 5
// 1
// 3
// 4

// 7