#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch=='+'){
        return 1;
    }else if(ch=='-'){
        return 1;
    }else if(ch=='*'){
        return 2;
    }else{
        return 2;
    }
}
int main(){
    string s;
    getline(cin,s);
    stack<string> post;
    stack<string> pre;
    stack<char> operators;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='('){
            operators.push(ch);
        }else if(ch==')'){
            while(operators.size()>0 and operators.top()!='('){
                char t = operators.top();
                operators.pop();
                string s = string(1,t);
                string post2 = post.top();
                post.pop();
                string post1 = post.top();
                post.pop();
                post.push(post1+post2+s);
                string pre2 = pre.top();
                pre.pop();
                string pre1 = pre.top();
                pre.pop();
                pre.push(s+pre1+pre2);
            }
            operators.pop();
        }else if(ch=='+' or ch=='-' or ch=='*' or ch=='/'){
            while(operators.size()>0 and operators.top()!='(' and precedence(ch)<=precedence(operators.top())){
                char t = operators.top();
                operators.pop();
                string s = string(1,t);
                string post2 = post.top();
                post.pop();
                string post1 = post.top();
                post.pop();
                post.push(post1+post2+s);
                string pre2 = pre.top();
                pre.pop();
                string pre1 = pre.top();
                pre.pop();
                pre.push(s+pre1+pre2);
            }
            operators.push(ch);
        }else if(ch>='0' and ch<='9' or ch>='a' and ch<='z' or ch>='A' and ch<='Z'){
            string s = string(1,ch);
            post.push(s);
            pre.push(s);
        }
    }
    while(operators.size()>0){
        char t = operators.top();
        operators.pop();
        string s = string(1,t);
        string post2 = post.top();
        post.pop();
        string post1 = post.top();
        post.pop();
        post.push(post1+post2+s);
        string pre2 = pre.top();
        pre.pop();
        string pre1 = pre.top();
        pre.pop();
        pre.push(s+pre1+pre2);
    }
    string postfix = post.top();
    string prefix = pre.top();
    cout<<"pre: "<<prefix<<endl;
    cout<<"post: "<<postfix<<endl;
    return 0;
}


// a*(b-c+d)/e
// pre: /*a+-bcde
// post: abc-d+*e/