#include<bits/stdc++.h>
using namespace std;
void printPermutations(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        string left = str.substr(0,i);
        string right = str.substr(i+1);
        string rest = left+right;
        printPermutations(rest,ans+ch);
    }
}
int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    return 0;
}
