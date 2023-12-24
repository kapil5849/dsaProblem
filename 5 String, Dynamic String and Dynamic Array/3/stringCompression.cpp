#include<bits/stdc++.h>
using namespace std;
string compression1(string s){
    string ans = "";
    ans+=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!=s[i-1]){
            ans+=s[i];
        }
    }
    return ans;
}
string compression2(string s){
    string ans = "";
    ans+=s[0];
    int cnt = 1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            cnt++;
        }else{
            if(cnt>1){
                ans+=to_string(cnt);
                cnt = 1;
            }
            ans+=s[i];
        }
    }
    if(cnt>1){
        ans+=to_string(cnt);
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<compression1(s)<<endl;
    cout<<compression2(s)<<endl;
    return 0;
}
