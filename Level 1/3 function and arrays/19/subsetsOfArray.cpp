#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int limit = pow(2,n);
    for(int i=0;i<limit;i++){
        int temp = i;
        string set = "";
        for(int j = n-1;j>=0;j--){
            int r = temp%2;
            temp = temp/2;
            if(r==0){
                set = "- "+set;
            }else{
                set = to_string(arr[j])+" "+set;
            }
        }
        cout<<set<<endl;
    }
    return 0;
}
