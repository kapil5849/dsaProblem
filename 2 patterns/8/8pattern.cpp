// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int space = n-1;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=space;j++){
//             cout<<"  ";
//         }
//         cout<<"* ";
//         space--;
//         cout<<endl;
//     }
//     return 0;
// }


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i+j==n+1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}