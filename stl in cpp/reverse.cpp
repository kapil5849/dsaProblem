#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {4,55,98,27,13,71};
    reverse(v.begin(),v.end());
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}