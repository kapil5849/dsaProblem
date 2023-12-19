#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int inv=0;
    int op=1;
    while(n!=0){
        int od=n%10;
        int id=op;
        int ip=od;
        inv=inv+id*pow(10,ip-1);
        n=n/10;
        op++;
    }
    cout<<inv<<endl;
    return 0;
}

// #include<iostream>
// #include<math.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int counter = 1;
//     int ans = 0;
//     while(n!=0){
//         int r = n%10;
//         n /=10;
//         ans += counter*pow(10,r-1);
//         counter++;
//     }
//     cout<<ans<<endl;
// }
