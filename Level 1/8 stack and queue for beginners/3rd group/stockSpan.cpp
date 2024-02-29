// next greater elements on left.
// 5 5 3 8 -2 7
// 9 2 5 9 3 1 12 6 8 7
// time complexity : n*O(1)=O(n).
// space complexity : O(n) : span vector.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> span(n,0);
    stack<int> st; // index... 
    span[0]=1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 and arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.size()==0){
            span[i]=i+1;
        }
        else{
            span[i]=i-st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    return 0;
}