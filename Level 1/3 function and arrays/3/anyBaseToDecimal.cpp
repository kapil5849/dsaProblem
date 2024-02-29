#include<iostream>
using namespace std;

int main(){
    int n,b;
    cin>>n>>b;
    int ans = 0, multi = 1;
    while(n){
        int rem = n%10;
        n/=10;
        ans+=rem*multi;
        multi*=b;
    }
    cout<<ans;
    return 0;
}