#include<bits/stdc++.h>
using namespace std;
int chocolates(int arr[], int n);
int main()
{
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        cout << chocolates(arr, n);
        cout << endl;
        
    }

}
int chocolates(int arr[], int n){
    int mn=arr[0];
    for(int i=1;i<n;i++){
        mn=min(mn,arr[i]);
    }
    return mn;
}