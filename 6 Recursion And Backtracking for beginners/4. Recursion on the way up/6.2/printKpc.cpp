#include<bits/stdc++.h>
using namespace std;
vector<string> codes = {".,","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
void printKpc(string s,string ans){
    if(s==""){
        cout<<ans<<endl;
        return;
    }
    int digit = s[0]-'0';
    string code = codes[digit];
    for(auto ch:code){
        printKpc(s.substr(1),ans+ch);
    }
}
int main(){
    string s;
    cin>>s;
    printKpc(s,"");
    return 0;
}
