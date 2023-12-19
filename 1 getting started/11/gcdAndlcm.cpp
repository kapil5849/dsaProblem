#include<bits/stdc++.h>
using namespace std;

int main(){
    int num1, num2;
    cin>>num1>>num2;
    int oNum1 = num1;  
    int oNum2 = num2;
    while(num1%num2!=0){
        int rem = num1%num2;
        num1=num2;
        num2=rem;
    }
    int gcd = num2;
    int lcm = (oNum1*oNum2)/gcd;
    cout<<"gcd : "<<gcd<<endl;
    cout<<"lcm : "<<lcm<<endl;
    return 0;
}
