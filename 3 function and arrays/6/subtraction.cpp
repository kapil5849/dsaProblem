#include<iostream>
using namespace std;
int main(){
    int b,n1,n2;
    cin>>b>>n1>>n2;
    int ans = 0, c = 0, p = 1;
    while(n2>0){
        int d1 = n1%10;
        int d2 = n2%10;
        n1/=10;
        n2/=10;
        int d = 0;
        d2=d2+c;
        if(d2>=d1){
            c = 0;
            d = d2-d1;
        }else{
            c=-1;
            d = d2+b-d1;
        }
        ans = ans + d * p;
        p = p* 10;
    }
    cout<<ans;
    return 0;
}