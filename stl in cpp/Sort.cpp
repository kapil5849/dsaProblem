#include<bits/stdc++.h>
using namespace std;

bool compare(string s1,string s2){
    return s1.length()<s2.length();
}
int main(){
    vector<int> v = {4,55,98,27,13,71};
    vector<int> v2 = {4,55,98,27,13,71};
    vector<string> v3 = {"apple","banana","pineapple","kiwi","kapil"};
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end(),greater<int>());
    sort(v3.begin(),v3.end(),compare);
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int j:v2){
        cout<<j<<" ";
    }
    cout<<endl;
    for(string k:v3){
        cout<<k<<" ";
    }
    return 0;
}