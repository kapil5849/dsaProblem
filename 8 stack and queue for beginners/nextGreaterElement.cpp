#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> nge(n,0);
    nge[n-1]=-1;
    stack<int> st;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]>=st.top()){
            st.pop();
        }
        if(st.size()==0){
            nge[i]=-1;
        }else{
            nge[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    return 0;
}

// next greater element on right
// 5 5 3 8 -2 7
// 9 2 5 9 3 1 12 6 8 7
// time complexity : O(n)
// space complexity : O(n)