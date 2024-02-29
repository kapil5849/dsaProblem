#include<bits/stdc++.h>
using namespace std;
int operationValue(int value1,int value2,char ch){
    if(ch=='+'){
        return value1+value2;
    }
    else if(ch=='-'){
        return value1-value2;
    }
    else if(ch=='*'){
        return value1*value2;
    }
    else if(ch=='/'){
        return value1/value2;
    }
    else{
        return 0;
    }
}
int main(){
    string s;
    getline(cin,s);
    stack<int> post;
    stack<string> pre;
    stack<string> in;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string temp = string(1,ch);
        if(ch=='+' or ch=='-' or ch=='*' or ch=='/'){
            int post2 = post.top();
            post.pop();
            int post1 = post.top();
            post.pop();
            int value = operationValue(post1,post2,ch);
            post.push(value);
            string pre2 = pre.top();
            pre.pop();
            string pre1 = pre.top();
            pre.pop();
            pre.push(ch+pre1+pre2);
            string in2 = in.top();
            in.pop();
            string in1 = in.top();
            in.pop();
            in.push("("+in1+ch+in2+")"); 
        }else{
            post.push(ch-'0');
            pre.push(temp);
            in.push(temp);
        }
    }
    cout<<pre.top()<<endl;
    pre.pop();
    cout<<in.top()<<endl;
    in.pop();
    cout<<post.top()<<endl;
    post.pop();
    return 0;
}


// 264*8/+3-

// 2
// ((2+((6*4)/8))-3)
// -+2/*6483


