#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> arr(n,0);
    for (int i = 0; i < arr.size(); i++) {
          cin>> arr[i];
    }
    int fee;
    cin>> fee;
    int o_bsp = -arr[0];
    int o_ssp = 0;
    for(int i=1;i<n;i++){
        int n_bsp = 0;
        int n_ssp = 0;
        if(o_ssp-arr[i]>o_bsp){
            n_bsp=o_ssp-arr[i];
        }else{
            n_bsp=o_bsp;
        }
        if(o_bsp+arr[i]-fee>o_ssp){
            n_ssp=arr[i]+o_bsp-fee;
        }else{
            n_ssp=o_ssp;
        }
        o_bsp=n_bsp;
        o_ssp=n_ssp;
    } 
    cout<<o_ssp<<endl;
    return 0;
}