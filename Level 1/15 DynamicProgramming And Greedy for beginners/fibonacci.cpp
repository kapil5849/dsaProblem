#include<bits/stdc++.h>
#include<vector>
using namespace std;

// int fib(int n){
//     if(n==0 or n==1){
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
// }

// int fib(int n){
//     if(n==0 or n==1){
//         return n;
//     }
//     int fibOne=fib(n-1);
//     int fibTwo=fib(n-2);
//     int fibAns= fibOne+fibTwo;
//     return fibAns;
// }

// memoized technique...
int fib(int n,int memo[]){
    if(n==0 or n==1){
        return n;
    }
    if(memo[n]!=0){
        return memo[n];
    }
    memo[n]=fib(n-1,memo)+fib(n-2,memo);
    return memo[n];
}


// int fib(int n){
//     vector<int> memo(n+1);
//     memo[0]=0;
//     memo[1]=1;
//     for(int i=2;i<=n;i++){
//         memo[i]=memo[i-1]+memo[i-2];
//     }
//     return memo[n];
// }

int main(){
    int n;
    cin>>n;

    // cout<<fib(n)<<endl;

    int memo[n+1]={0};
    cout<<fib(n,memo)<<endl;

    // cout<<fib(n)<<endl;


    return 0;
}