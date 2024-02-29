#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mpi_st = 0;
    int least_sf = arr[0];
    vector<int> dpm_pis_ut(n,0);
    for(int i=1;i<n;i++){
        if(arr[i]<least_sf){
            least_sf=arr[i];
        }
        mpi_st=arr[i]-least_sf;
        if(mpi_st>dpm_pis_ut[i-1]){
            dpm_pis_ut[i]=mpi_st;
        }else{
            dpm_pis_ut[i]=dpm_pis_ut[i-1];
        }
    }
    int mpi_bt = 0;
    int max_at = arr[n-1];
    vector<int> dpm_pib_ut(n,0);
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max_at){
            max_at=arr[i];
        }
        mpi_bt=max_at-arr[i];
        if(mpi_bt>dpm_pib_ut[i+1]){
            dpm_pib_ut[i]=mpi_bt;
        }else{
            dpm_pib_ut[i]=dpm_pib_ut[i+1];
        }
    }
    int op = 0;
    for(int i=0;i<n;i++){
        if(dpm_pib_ut[i]+dpm_pis_ut[i]>op){
            op=dpm_pib_ut[i]+dpm_pis_ut[i];
        }
    }
    cout<<op<<endl;
    return 0;
}