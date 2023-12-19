#include<bits/stdc++.h>
using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    return x*power(x,n-1);
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
