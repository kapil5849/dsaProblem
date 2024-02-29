#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,target;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    vector<vector<bool>> dp(n+1,vector<bool>(target+1));
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(i==0 and j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){
                dp[i][j]=true;
            }
            else{
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }else{
                    int value = arr[i-1];
                    if(j>=value){
                        if(dp[i-1][j-value]==true){
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
    }
    // cout<<dp[n][target];
    if(dp[n][target]==1){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}

// 5
// 4
// 2
// 7
// 1
// 3
// 10