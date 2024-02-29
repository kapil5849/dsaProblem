// [(a + b) + {(c + d) * (e / f)}]
// time complexity : O(n)
// space complexity : O(1).  ----> The space complexity is O(n). Why? We are continuously popping and 
// pushing the elements from the stack. So why O(n)? Well, let me ask you a question. What can be the
// maximum size of the stack? Yes, it can be equal to the length of the string if we can input 
// the string with all opening brackets. It is after the string gets completely scanned that we 
// will realize that the brackets are not balanced. Otherwise, we keep on pushing all the opening
// brackets into the stack.

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' or ch=='[' or ch=='{'){
            st.push(ch);
        }
        else if(ch==')'){
            if(st.empty() or st.top()!='('){
                cout<<"unbalanced";
                return 0;
            }else{
                st.pop();
            }
        }
        else if(ch==']'){
            if(st.empty() or st.top()!='['){
                cout<<"unbalanced";
                return 0;
            }else{
                st.pop();
            }
        }
        else if(ch=='}'){
            if(st.empty() or st.top()!='{'){
                cout<<"unbalanced";
                return 0;
            }else{
                st.pop();
            }
        }
    }
    if(st.empty()){
        cout<<"balanced";
    }else{
        cout<<"unbalanced";
    }
    return 0;
}