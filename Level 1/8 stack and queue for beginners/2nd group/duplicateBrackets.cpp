// (a + b) + ((c + d))
// time complexity : O(2*n)=O(n)...
// space complexity : O(n) -> in worst case explain my code in steps.
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch==')'){
            if(st.top()=='('){
                cout<<"Duplicate brackets present"<<endl;
                return 0;
            }else{
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
        }else{
            st.push(ch);
        }
    }
    cout<<"Duplicate brackets absent"<<endl;
    return 0;
}