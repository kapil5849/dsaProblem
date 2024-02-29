#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>=2){
        int i=st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if(arr[i][j]==1){
            st.push(j);
        }else{
            st.push(i);
        }
    }
    int pot = st.top();
    st.pop();
    for(int i=0;i<n;i++){
        if(i!=pot){
            if(arr[i][pot]==0 or arr[pot][i]==1){
                cout<<"none";
            }
        }
    }
    cout<<"celebrity : "<<pot;
    return 0;
}