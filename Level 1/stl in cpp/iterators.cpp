#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {4,55,98,27,13,71};
    vector<int>:: iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}