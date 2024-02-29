// 17 2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6 4
// time complexity : 
// space complexity : 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> nge(n,0);
    nge[n-1]=n;
    stack<int> st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.size()==0){
            nge[i]=n;
        }else{
            nge[i]=st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n-k+1;i++){
        int j = i;
        while(nge[j]<i+k){
            j=nge[j];
        }
        cout<<arr[j]<<" ";
    }
    return 0;
}