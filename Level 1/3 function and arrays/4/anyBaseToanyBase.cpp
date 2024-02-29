#include<iostream>
using namespace std;

int main(){
    int n,b1,b2;
    cin>>n>>b1>>b2;
    int ans1 = 0, multi1 = 1;
    while(n){
        int rem = n%10;
        n/=10;
        ans1+=rem*multi1;
        multi1*=b1;
    }
    int ans2 = 0, multi2 = 1;
    while(ans1){
        int rem = ans1%b2;
        ans1/=b2;
        ans2+=rem*multi2;
        multi2*=10;
    }
    cout<<ans2;
    return 0;
}