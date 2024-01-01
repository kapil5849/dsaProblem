#include<iostream>
using namespace std;
int main(){
    int n,b;
    cin>>n>>b;
    int ans = 0, multi = 1;
    while(n){
        int rem = n%b;
        n/=b;
        ans+=rem*multi;
        multi*=10;
    }
    cout<<ans;
    return 0;
}
