#include<bits/stdc++.h>
using namespace std;
vector<string> codes = {".,","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> getKpc(string s){
    if(s.length()==0){
        vector<string> temp;
        temp.push_back("");
        return temp;
    }
    char ch = s[0];
    string ros = s.substr(1);
    vector<string> res = getKpc(ros);
    vector<string> ans;
    int idx = ch-'0';
    for(int i=0;i<codes[idx].size();i++){
        char ch = codes[idx].at(i);
        for(string str:res){
            ans.push_back(ch+str);
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    vector<string> ans = getKpc(s);
    cout<<"[";
    int cnt = 0;
    for(auto str:ans){
        if(cnt!=ans.size()-1){
            cout<<str<<", ";
        }else{
            cout<<str;
        }
        cnt++;
    }
    cout<<"]";
    return 0;
}
