// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,k;
//     cin>>n>>k;
//     vector<vector<int>> arr(n,vector<int>(k));
//     for(int i=0;i<arr.size();i++){
//         for(int j=0;j<arr[0].size();j++){
//             cin>>arr[i][j];
//         }
//     }
//     vector<vector<int>> dp(arr.size(),vector<int>(arr[0].size()));
//     for(int j=0;j<arr[0].size();j++){
//         dp[0][j]=arr[0][j];
//     }
//     for(int i=1;i<arr.size();i++){
//         for(int j=0;j<arr[0].size();j++){
//             int min = INT_MAX;
//             for(int l=0;l<arr[0].size();l++){
//                 if(l!=j){
//                     if(dp[i-1][l]<min){
//                         min=dp[i-1][l];
//                     }
//                 }
//             }
//             dp[i][j]=arr[i][j]+min;
//         }
//     }
//     int min = INT_MAX;
//     for(int j=0;j<k;j++){
//         if(dp[n-1][j]<min){
//             min = dp[n-1][j];
//         }
//     }
//     cout<<min<<endl;
//     return 0;
// }


// time complexity will reduce n^3 to n^2... 



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n,vector<int>(k));
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(arr.size(),vector<int>(arr[0].size()));
    int least = INT_MAX;
    int sLeast = INT_MAX;
    for(int j=0;j<arr[0].size();j++){
        dp[0][j]=arr[0][j];
        if(arr[0][j]<=least){
            sLeast=least;
            least=arr[0][j];
        }else if(arr[0][j]<=sLeast){
            sLeast = arr[0][j];
        }
    }
    for(int i=1;i<arr.size();i++){
        int nLeast=INT_MAX;
        int nsLeast=INT_MAX;
        for(int j=0;j<arr[0].size();j++){
            if(least==arr[i][j]){
                dp[i][j]=sLeast+arr[i][j];
            }else{
                dp[i][j]=least+arr[i][j];
            }
            if(dp[i][j]<=nLeast){
            nsLeast=nLeast;
            nLeast=dp[i][j];
            }else if(dp[i][j]<=nsLeast){
                nsLeast=dp[i][j];
            }
        }
        least=nLeast;
        sLeast=nsLeast;
    }
    cout<<least<<endl;
    return 0;
}

// 4 3
// 1 5 7
// 5 8 4
// 3 2 9
// 1 2 4