#include<bits/stdc++.h>
using namespace std;
void printEncodings(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }else if(s.length()==1){
        char ch = s[0];
        if(ch=='0'){
            return;
        }else{
            int chv = ch-'0';
            char code = 'a'+chv-1;
            cout<<ans+code<<endl;
        }
    }else{
        char ch = s[0];
        string left = s.substr(1);
        if(ch=='0'){
            return;
        }else{
            int chv = ch-'0';
            char code = 'a'+chv-1;
            printEncodings(left,ans+code);
        }
        string ch12 = s.substr(0,2);
        string ros2 = s.substr(2);
        int ch12v = stoi(ch12);
        if(ch12v<=26){
            char code = 'a'+ch12v-1;
            printEncodings(ros2,ans+code);
        }
    }
}
int main(){
    string s;
    cin>>s;
    printEncodings(s,"");
    return 0;
}