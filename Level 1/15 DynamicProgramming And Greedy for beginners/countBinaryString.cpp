#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dpz(n+1,0);
    vector<int> dpo(n+1,0);
    dpz[1]=1;
    dpo[1]=1;
    for(int i=2;i<=n;i++){
        dpo[i]=dpo[i-1]+dpz[i-1];
        dpz[i]=dpo[i-1];
    }
    cout<<(dpo[n]+dpz[n])<<endl;
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int ocz=1;
//     int oco=1;
//     for(int i=2;i<=n;i++){
//         int ncz = oco;
//         int nco = oco+ocz;
//         oco=nco;
//         ocz=ncz;
//     }
//     cout<<(oco+ocz)<<endl;
//     return 0;
// }


// for n = 6 the answer is 21...