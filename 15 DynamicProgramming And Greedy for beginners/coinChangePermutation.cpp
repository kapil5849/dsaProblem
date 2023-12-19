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
    for(int i=1;i<dp.size();i++){
        for(int j=0;j<arr.size();j++){
            if(arr[j]<=i){
                dp[i]+=dp[i-arr[j]];
            }
        }
    }
    cout<<dp[amount]<<endl;
    return 0;
}