#include<iostream>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int cnt = 0;
    while(n){
        if(n%10==d){
           cnt++;
       }
       n/=10;
    }
    cout<<cnt;
    return 0;
}
