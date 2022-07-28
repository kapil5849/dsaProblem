#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    unordered_map<char,int> mpp;
    for(int i=0;i<str.length();i++){
        mpp[str[i]]++;
    }
    // cout<<mpp[j]<<" , "<<mpp[q]<<endl;
    int maxCount=0;
    char ch;
    for(pair<char,int> m:mpp){
        if(m.second > maxCount){
            maxCount=m.second;
            ch=m.first;
        }
    }
    cout<<ch<<endl;
    return 0;
}