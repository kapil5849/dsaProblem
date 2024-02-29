#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<int> st;
    int cnt = 1;
    for(int i=0;i<=s.length();i++){
        st.push(cnt);
        cnt++;
        if(s[i]=='i' or i==s.length()){
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
        }
    }
    return 0;
}