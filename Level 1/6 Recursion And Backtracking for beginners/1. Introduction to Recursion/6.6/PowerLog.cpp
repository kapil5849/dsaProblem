#include<bits/stdc++.h>
using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    int xpnb2 = power(x,n/2);
    int xn = xpnb2*xpnb2;
    if(n%2==1){
        xn = xn*x;
    }
    return xn;
}
int main(){
    int x,n;
    cout<<"Enter the base: ";
    cin>>x;
    cout<<"Enter the power: ";
    cin>>n;
    cout<<"The power of "<<x<<"^"<<n<<" is: "<<power(x,n);
    return 0;
}
