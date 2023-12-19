#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,amount;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>amount;
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int i=0;i<arr.size();i++){
        for(int j=arr[i];j<dp.size();j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    cout<<dp[amount]<<endl;
    return 0;
}

// 3
// 2
// 3
// 5
// 7
