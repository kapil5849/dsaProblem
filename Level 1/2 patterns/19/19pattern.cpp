#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        if(i==1){
            if(j==n or j<=n/2+1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }else if(i<=n/2){
            if(j==n or j==n/2+1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }else if(i==n/2+1){
            cout<<"* ";
        }else if(i<n){
            if(j==1 or j==n/2+1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }else{
            if(j==1 or j>=n/2+1){
                cout<<"* ";
            }else{
                cout<<"  ";
        }
        }
    }
    cout<<endl;
    }
    return 0;
}
