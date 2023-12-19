#include<bits/stdc++.h>
using namespace std;
int powerofTwo(int n){
    int i=1;
    while(i*2<=n){
        i=i*2;
    }
    return i;
}
int solution(int n){
    int hpt=powerofTwo(n);
    int l = n-hpt;
    return 2*l+1;
}
int main(){
    int n;
    cin>>n;
    cout<<solution(n);
    return 0;
}

