#include<bits/stdc++.h>
using namespace std;
vector<int> mergeTwoSortedArray(vector<int> & a, vector<int> & b){
    int i=0,j=0,k=0;
    vector<int> c(a.size()+b.size());
    while(i<a.size() and j<b.size()){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<a.size()){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<b.size()){
        c[k]=b[j];
        j++;
        k++;
    }
    return c;
}
vector<int> mergeSort(vector<int> arr,int low, int high){
    if(low==high){
        vector<int> base(1);
        base[0]=arr[low];
        return base;
    }
    int mid = (low+high)/2;
    vector<int> fsh = mergeSort(arr,low,mid);
    vector<int> lsh = mergeSort(arr,mid+1,high);
    vector<int> final = mergeTwoSortedArray(fsh,lsh);
    return final;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = mergeSort(arr,0,n-1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<", ";
    }
    return 0;
}