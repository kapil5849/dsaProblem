#include<iostream>
using namespace std;
int main(){
    int b,n1,n2;
    cin>>b>>n1>>n2;
    int sum = 0, carry = 0, multi = 1, result = 0;
    while(n1>0 or n2>0 or carry>0){
        int rem1=n1%10;
        int rem2=n2%10;
        int sum = rem1+rem2+carry;
        carry = sum/b;
        int value = sum%b;
        result += value*multi;
        multi *= 10;
        n1 /= 10;
        n2 /= 10;
    }
    cout<<result;
    return 0;
}

