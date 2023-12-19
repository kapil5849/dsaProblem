#include<bits/stdc++.h>
using namespace std;
void PrintInc(int n){
    if(n<=0){
        return;
    }
    PrintInc(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The increasing order is: ";
    PrintInc(n);
    return 0;
}
