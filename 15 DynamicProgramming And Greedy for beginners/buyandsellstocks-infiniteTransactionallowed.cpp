#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int bd = 0;
    int sd = 0;
    int profit = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            sd++;
        }
        else{
            profit += arr[sd]-arr[bd];
            sd=bd=i;
        }
    }
    profit += arr[sd]-arr[bd];
    cout<<profit<<endl;
    return 0;
}