#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<long long>> dp(k+1,vector<long long>(n+1,0));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i>j){
                dp[i][j]=0;
            }
            else if(i==j){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=i*dp[i][j-1]+dp[i-1][j-1];
            }
        }
    }
    cout<<dp[k][n]<<endl;
    return 0;
}

