#include<bits/stdc++.h>
using namespace std;
void PrintDec(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    PrintDec(n-1);
    return;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The decreasing order is: ";
    PrintDec(n);
    return 0;
}
