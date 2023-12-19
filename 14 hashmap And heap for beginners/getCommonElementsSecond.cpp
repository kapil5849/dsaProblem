#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	int arr1[n];
	unordered_map<int,int> mpp;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
		mpp[arr1[i]]++;
	}
	cin>>m;
	int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
        if(mpp.find(arr2[i])!=mpp.end() and mpp[arr2[i]]!=0){
            cout<<arr2[i]<<endl;
            mpp[arr2[i]]--;
        }
    }
    return 0;
}