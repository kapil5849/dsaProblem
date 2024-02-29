#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int space = 1;
    int star = n/2+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=star;j++){
            cout<<"* ";
        }
        for(int j=1;j<=space;j++){
            cout<<"  ";
        }
        for(int j=1;j<=star;j++){
            cout<<"* ";
        }
        // cout<<star<<", "<<space<<", "<<star<<endl;
        if(i<=n/2){
            star--;
            space+=2;
        }else{
            star++;
            space-=2;
        }
        cout<<endl;
    }
    return 0;
}
