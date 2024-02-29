#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> &arr){
    int ans = 0,x=0,y=0;
    for(auto val:arr){
        ans ^= val;
    }
    int rms = ans & -ans;
    for(auto val:arr){
        if((val & rms)==0){
            x ^= val;
        }else{
            y ^= val;
        }
    }
    if(x<y){
        cout<<x<<endl;
        cout<<y<<endl;
    }else{
        cout<<y<<endl;
        cout<<x<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solution(arr);
    return 0;
}