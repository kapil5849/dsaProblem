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
}
int main(){
    string s;
    cin>>s;
    stack<int> pre;
    stack<string> in;
    stack<string> post;
    for(int i=s.length()-1;i>=0;i--){
        char ch = s[i];
        string temp = string(1,ch);
        if(ch=='+' or ch=='-' or ch=='*' or ch=='/'){
            int value1 = pre.top();
            pre.pop();
            int value2 = pre.top();
            pre.pop();
            int value = operationValue(value1,value2,ch);
            pre.push(value);
            string in1 = in.top();
            in.pop();
            string in2 = in.top();
            in.pop();
            in.push("("+in1+ch+in2+")");
            string post1 = post.top();
            post.pop();
            string post2 = post.top();
            post.pop();
            post.push(post1+post2+ch);
        }else{
            pre.push(ch-'0');
            in.push(temp);
            post.push(temp);
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

// -+2/*6483

// 2
// ((2+((6*4)/8))-3)
// 264*8/+3-