#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(int i=1;i<s.length();i++){
        int diff=s[i]-s[i-1];
        cout<<s[i-1]<<diff;
    }
    cout<<s[s.length()-1]<<endl;
    return 0;
}
