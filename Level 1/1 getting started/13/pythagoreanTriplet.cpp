#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int maxi = a;
    if(b>maxi)
        maxi = b;
    if(c>maxi)
        maxi = c;
    if(maxi==a){
        bool flag = (a*a == b*b + c*c);
        cout<<flag;
    }
    else if(maxi==b){
        bool flag = (b*b == a*a + c*c);
        cout<<flag;
    }
    else{
        bool flag = (c*c == b*b + a*a);
        cout<<flag;
    }
    return 0;
}