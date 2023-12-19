#include<bits/stdc++.h>
using namespace std;
void PrintZigzag(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    PrintZigzag(n-1);
    cout<<n<<" ";
    PrintZigzag(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    PrintZigzag(n);
    return 0;
}