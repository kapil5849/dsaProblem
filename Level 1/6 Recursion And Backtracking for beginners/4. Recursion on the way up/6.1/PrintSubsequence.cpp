#include<bits/stdc++.h>
using namespace std;
void printSS(string str, string ans){
    if(str==""){
        cout<<ans<<endl;
        return;
    }
    printSS(str.substr(1), ans + str[0]);
    printSS(str.substr(1), ans);
}
int main(){
    string str;
    cin>>str;
    printSS(str, "");
    return 0;
}