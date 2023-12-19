#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,k,m;
    cin>>n>>i>>j>>k>>m;
    int onMask = 1<<i;
    int offMask = ~(1<<j);
    int tMask = 1<<k;
    int cMask = 1<<m;
    cout<<(n | onMask)<<endl;
    cout<<(n & offMask)<<endl;
    cout<<(n ^ tMask)<<endl;
    if((n & cMask)!=0){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}