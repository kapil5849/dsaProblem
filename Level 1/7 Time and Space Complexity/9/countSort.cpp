#include<bits/stdc++.h>
using namespace std;
void countSort(vector<int> &arr,int min, int max){
    int range = max-min+1;
    vector<int> freq(range,0);
    for(int i=0;i<arr.size();i++){
        int idx = arr[i]-min;
        freq[idx]++;
    }
    for(int i=1;i<freq.size();i++){
        freq[i]=freq[i]+freq[i-1];
    }
    vector<int> ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
        int value = arr[i];
        int pos = freq[value-min];
        int index = pos-1;
        ans[index]=value;
        freq[value-min]--;
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=ans[i];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }
    countSort(arr,mini,maxi);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}