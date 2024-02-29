#include<iostream>
using namespace std;
int sum(int b,int n1,int n2){
    int ans = 0, c=0, p=1;
    while(n1>0 or n2>0 or c>0){
        int d1 = n1%10;
        int d2 = n2%10;
        n1/=10;
        n2/=10;
        int sum = d1+d2+c;
        c = sum/b;
        int val = sum%b;
        ans = ans + val * p;
        p = p * 10;
    }
    return ans;
}
int singleMulti(int b, int n, int d){
    int c= 0,result=0,p=1;
    while(n>0 or c>0){
        int d1 = n%10;
        n/=10;
        int multi = d1*d+c;
        c=multi/b;
        multi = multi%b;
        result = result+multi*p;
        p= p*10;
    }
    return result;
}
int main(){
    int b,n1,n2;
    cin>>b>>n1>>n2;
    int ans=0,p=1;
    while(n2>0){
        int d2= n2%10;
        n2/=10;
        int sp = singleMulti(b,n1,d2);
        ans=sum(b,ans,sp*p);
        p=p*10;
    }
    cout<<ans<<endl;
    return 0;
}
