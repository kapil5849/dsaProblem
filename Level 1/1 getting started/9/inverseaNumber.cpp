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
