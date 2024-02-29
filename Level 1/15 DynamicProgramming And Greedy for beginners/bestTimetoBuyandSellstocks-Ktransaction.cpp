// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,k;
//     cin>>n;
//     vector<int> arr(n,0);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cin>>k;
//     vector<vector<int>> dp(k+1,vector<int>(n));
//     for(int t=1;t<=k;t++){
//         for(int d=1;d<arr.size();d++){
//             int max = dp[t][d-1];
//             for(int pd=0;pd<d;pd++){
//                 int value = dp[t-1][pd];
//                 int gap = arr[d]-arr[pd];
//                 if(value+gap>max){
//                     max=value+gap;
//                 }
//             }
//             dp[t][d]=max;
//         }
//     }
//     cout<<dp[k][n-1];
//     return 0;
// }


// optimal solution...

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    vector<vector<int>> dp(k+1,vector<int>(n));
    for(int t=1;t<=k;t++){
        int max = INT_MIN;
        for(int d=1;d<arr.size();d++){
            if(dp[t-1][d-1]-arr[d-1]>max){
                max=dp[t-1][d-1]-arr[d-1];
            }
            if(max+arr[d]>dp[t][d-1]){
                dp[t][d]=max+arr[d];
            }else{
                dp[t][d]=dp[t][d-1];
            }
        }
    }
    cout<<dp[k][n-1];
    return 0;
}


