#include<bits/stdc++.h>
using namespace std;  
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    int fact = factorial(n);
    for(int i=0;i<fact;i++){
        int temp = i;
        string ans = s;
        for(int div=n;div>=1;div--){
            int q = temp/div;
            int r = temp%div;
            cout<<ans[r];
            ans.erase(ans.begin()+r);
            temp = q;
        }
        cout<<endl;
    }
    return 0;
}
