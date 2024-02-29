// #include<bits/stdc++.h>
// using namespace std;
// bool isPalindrome(string s){
//     int i = 0, j = s.length()-1;
//     while(i<j){
//         if(s[i]!=s[j]){
//             return false;
//         }
//         else{
//             i++;
//             j--;
//         }
//     }
//     return true;
// }
// int main(){
//     string s;
//     cin>>s;
//     for(int i=0;i<s.length();i++){
//         for(int j=i+1;j<=s.length();j++){
//             string ss = s.substr(i,j-i);
//             if(isPalindrome(ss)){
//                 cout<<ss<<endl;
//             }
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    int left = 0, right = s.length()-1;
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }else{
            left++;
            right--;
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<=s.length();j++){
            string ss = s.substr(i,j-i);
            if(isPalindrome(ss)){
                cout<<ss<<endl;
            }
        }
    }
    return 0;
}