#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < arr.size(); i++) {
       cin>> arr[i] ;
    }
    int o_bsp = -arr[0];
    int o_ssp = 0;
    int o_csp = 0;
    for(int i=1;i<n;i++){
        int n_bsp=0;
        int n_ssp=0;
        int n_csp=0;
        if(o_csp-arr[i]>o_bsp){
            n_bsp=o_csp-arr[i];
        }else{
            n_bsp=o_bsp;
        }
        if(arr[i]+o_bsp>o_ssp){
            n_ssp=arr[i]+o_bsp;
        }else{
            n_ssp=o_ssp;
        }
        if(o_ssp>o_csp){
            n_csp=o_ssp;
        }else{
            n_csp=o_csp;
        }
        o_bsp=n_bsp;
        o_ssp=n_ssp;
        o_csp=n_csp;
    }
    cout<<o_ssp<<endl;
    return 0;
}