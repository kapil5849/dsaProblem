#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int space = 2*n-3;
    int star = 1;
    for(int i=1;i<=n;i++){
        int val = 1;
        for(int j=1;j<=star;j++){
            cout<<val<<" ";
            val++;
        }
        for(int j=1;j<=space;j++){
            cout<<"  ";
        }
        if(i==n){
            star--;
            val--;
        }
        for(int j=1;j<=star;j++){
            val--;
            cout<<val<<" ";
        }
        space-=2;
        star++;
        cout<<endl;
    }
    return 0;
}
