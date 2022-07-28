#include<bits/stdc++.h>
using namespace std;
bool compare(string s1,string s2){
    return s1.length()<s2.length();
}
int main(){
    int a = 15,b = 27;
    cout<<min(a,b)<<endl;
    cout<<max(a,b)<<endl;
    string s1 = "orange",s2 = "mango";
    cout<<min(s1,s2,compare)<<endl;
    cout<<max(s1,s2,compare)<<endl;
    vector<int> v = {4,55,98,27,13,71};
    cout<<*min_element(v.begin(),v.end())<<endl;
    cout<<*max_element(v.begin(),v.end())<<endl;
    vector<string> vv = {"kap","mango","orangeKa","so"};
    cout<<*min_element(vv.begin(),vv.end(),compare)<<endl;
    cout<<*max_element(vv.begin(),vv.end(),compare)<<endl;
    return 0;
}