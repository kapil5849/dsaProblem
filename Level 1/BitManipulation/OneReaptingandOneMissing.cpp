#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> &arr){
    int ans = 0;
    for(auto ele:arr){
        ans = ans ^ ele;
    }
    for(int i=1;i<=arr.size();i++){
        ans = ans ^ i;
    }
    int rms = ans & (-ans);
    int x = 0;
    int y = 0;
    for(auto ele:arr){
        if((ele & rms)==0){
            x = x ^ ele;
        }else{
            y = y ^ ele;
        }
    }
    for(int i=1;i<=arr.size();i++){
        if((i & rms)==0){
            x = x ^ i;
        }else{
            y = y ^ i;
        }
    }
    for(auto ele:arr){
        if(ele==x){
            cout<<"Missing Number -> "<<y<<endl;
            cout<<"Repeating Number -> "<<x<<endl;
            break;
        }else if(ele==y){
            cout<<"Missing Number -> "<<x<<endl;
            cout<<"Repeating Number -> "<<y<<endl;
            break;
        }
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