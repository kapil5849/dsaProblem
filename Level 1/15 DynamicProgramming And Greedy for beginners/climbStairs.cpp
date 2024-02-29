#include<bits/stdc++.h>
using namespace std;

int cs(int n){
    if(n==0 or n==1){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return cs(n-1)+cs(n-2)+cs(n-3);
}

int csSecond(int n,int dp[]){
    
    if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    return csSecond(n-1,dp)+csSecond(n-2,dp)+csSecond(n-3,dp);
}

int csThird(int n){
    vector<int> memo(n+1);
    memo[0]=1;
    memo[1]=1;
    for(int i=2;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2]+memo[i-3];
    }
    return memo[n];
}
int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
    cout<<csSecond(n,new int [n+1])<<endl;
    cout<<csThird(n)<<endl;
    return 0;
}

// #include <bits/stdc++.h>
// #include<vector>
// using namespace std;
// int cs(int n){
//     vector<int> dp(n+1);
//     dp[0]=1;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//         cout<<dp[i]<<endl;
//     }
//     return dp[n];
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<cs(n)<<endl;
//     return 0;
// }