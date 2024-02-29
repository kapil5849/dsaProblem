#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {4,13,27,55,71,98};
    cout<<binary_search(v.begin(),v.end(),27)<<endl;
    cout<<binary_search(v.begin(),v.end(),44)<<endl;
    return 0;
}