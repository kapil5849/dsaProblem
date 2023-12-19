// #include <iostream>
// #include <stack>
// using namespace std;

// bool hasExtraBrackets(const string& exp) {
//     stack<char> brackets;

//     // Step 3: Iterate through each character in the expression
//     for (char c : exp) {
//         // Step 4: If the current character is a closing bracket
//         if (c == ')' || c == ']' || c == '}') {
//             // Step 4a: Check if the stack is not empty and the top element is a matching opening bracket
//             if (!brackets.empty() && ((c == ')' && brackets.top() == '(') ||
//                                       (c == ']' && brackets.top() == '[') ||
//                                       (c == '}' && brackets.top() == '{'))) {
//                 // Step 4b: Pop the top element from the stack
//                 brackets.pop();
//             } else {
//                 // Step 4c: Push the current closing bracket onto the stack
//                 brackets.push(c);
//             }
//         }
//         // Step 5: If the current character is an opening bracket
//         else if (c == '(' || c == '[' || c == '{') {
//             // Step 5: Push it onto the stack
//             brackets.push(c);
//         }
//     }

//     // Step 6: Check if the stack is empty
//     return brackets.empty();
// }

// int main() {
//     string exp;
//     getline(cin, exp);

//     // Step 1: Read the expression input

//     // Step 2: Call the function to check for extra brackets
//     if (hasExtraBrackets(exp)) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }

//     // Step 7: End the program

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    string flag="false";
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch==')'){
            if(st.top()=='('){
                flag="true";
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
    cout<<flag<<endl;
    return 0;
}

// (a + b) + ((c + d))
// time complexity : O(2*n)=O(n)...
// space complexity : O(n) -> in worst case explain my code in steps.

