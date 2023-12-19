#include<bits/stdc++.h>
using namespace std;
vector<string> getSubsequence(string s){
    if(s.length()==0){
        vector<string> base;
        base.push_back("");
        return base;
    }
    char firstChar = s[0];
    string ros = s.substr(1);
    vector<string> ansRos = getSubsequence(ros);
    vector<string> ans;
    for(auto val:ansRos){
        ans.push_back(""+val);
    }
    for(auto val:ansRos){
        ans.push_back(firstChar+val);
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    vector<string> temp = getSubsequence(s);
    cout<<"[";
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<",";
    }
    cout<<"]";
    return 0;
}
