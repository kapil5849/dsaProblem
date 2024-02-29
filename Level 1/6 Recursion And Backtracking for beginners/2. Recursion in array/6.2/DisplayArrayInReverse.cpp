#include<bits/stdc++.h>
using namespace std;
void displayReverse(int a[],int n,int i){
    if(i<0){
        return;
    }
    cout<<a[i]<<" ";
    displayReverse(a,n,i-1);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    displayReverse(a,n,n-1);
    return 0;
}
