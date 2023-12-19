#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long same = k*1;
    long long diff = k*(k-1);
    long long total = same + diff;
    for(int i=3;i<=n;i++){
        same = diff;
        diff = total*(k-1);
        total = same + diff;
    }
    cout<<total<<endl;
    return 0;
}