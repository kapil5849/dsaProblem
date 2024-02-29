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
int operationValue(int value1,int value2,char ch){
    if(ch=='+'){
        return value1+value2;
    }else if(ch=='-'){
        return value1-value2;
    }else if(ch=='*'){
        return value1*value2;
    }else{
        return value1/value2;
    }
}
int main(){
    string s;
    getline(cin,s);
    stack<int> operands;
    stack<char> operators;                  
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='('){
            operators.push(ch);
        }else if(isdigit(ch)){
            operands.push(ch-'0');
        }else if(ch==')'){
            while(operators.size()>0 and operators.top()!='('){
                int value2 = operands.top();
                operands.pop();
                int value1 = operands.top();
                operands.pop();
                char ch = operators.top();
                operators.pop();
                int value = operationValue(value1,value2,ch);
                operands.push(value);
            }
            operators.pop();
        }else if(ch=='+' or ch=='-' or ch=='*' or ch=='/'){
            while(operators.size()>0 and operators.top()!='(' and precedence(ch)<=precedence(operators.top())){
                int value2 = operands.top();
                operands.pop();
                int value1 = operands.top();
                operands.pop();
                char ch = operators.top();
                operators.pop();
                int value = operationValue(value1,value2,ch);
                operands.push(value);
            }
            operators.push(ch);
        }
    }
    while(operators.size()>0){
        int value2 = operands.top();
        operands.pop();
        int value1 = operands.top();
        operands.pop();
        char ch = operators.top();
        operators.pop();
        int value = operationValue(value1,value2,ch);
        operands.push(value);
    }
    int answer = operands.top();
    operands.pop();
    cout<<answer<<endl;
    return 0;
}

// 2 + 6 * 4 / 8 - 3
// 2
