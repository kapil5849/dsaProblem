#include<bits/stdc++.h>
using namespace std;
void PrintIncDec(int n){
    if(n<=0){
        return;
    }
    cout<<n<<" ";
    PrintIncDec(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The order is: ";
    PrintIncDec(n);
    return 0;
}
