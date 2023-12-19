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
    vector<int> dp(cap+1);
    dp[0]=0;
    for(int bc=1;bc<=cap;bc++){
        int max = 0;
        for(int i=0;i<n;i++){
            if(weight[i]<=bc){
                int rBc = bc-weight[i];
                int rBv = dp[rBc];
                int tBv = rBv+value[i];
                if(tBv>max){
                    max=tBv;
                }
            }
        }
        dp[bc]=max;
    }
    cout<<dp[cap]<<endl;
    return 0;
}


// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7