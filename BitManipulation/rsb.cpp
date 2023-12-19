#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int onesComp = ~n;
    cout<<onesComp<<bitset<8>(onesComp).to_string()<<endl;
    int twosComp = onesComp+1;
    cout<<twosComp<<bitset<8>(twosComp).to_string()<<endl;
    int x = n & twosComp;
    cout<<x<<endl;
    // int x =  (n&-n);
    cout<<x<<":"<<bitset<8>(x).to_string()<<endl;
    return 0;
}

// 58  => 10