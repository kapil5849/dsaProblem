#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int star = n;
    int space = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=space;j++){
            cout<<"  ";
        }
        for(int j=1;j<=star;j++){
            if(i>1 and i<=n/2 and j>1 and j<star){
                cout<<"  ";
            }else{
                cout<<"* ";
            }
        }
        if(i<=n/2){
            star-=2;
            space++;
        }else{
            star+=2;
            space--;
        }
        cout<<endl;
    }
    return 0;
}
