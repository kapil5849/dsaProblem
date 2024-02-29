#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterOnRight(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    ans[n-1]=-1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
vector<int> nextGreaterOnLeft(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    ans[0]=-1;
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        while(st.size()>0 and arr[i]>=st.top()){
            st.pop();
        }
        if(st.size()==0){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
vector<int> nextSmallerOnRight(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    ans[n-1]=-1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]<=st.top()){
            st.pop();
        }
        if(st.size()==0){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
vector<int> nextSmallerOnLeft(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    ans[0]=-1;
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        while(st.size()>0 and arr[i]<=st.top()){
            st.pop();
        }
        if(st.size()==0){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = nextGreaterOnRight(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" -> "<<ans[i]<<endl;
    }
    cout<<"-----------------"<<endl;
    vector<int> ans2 = nextGreaterOnLeft(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" -> "<<ans2[i]<<endl;
    }
    cout<<"-----------------"<<endl;
    vector<int> ans3 = nextSmallerOnRight(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" -> "<<ans3[i]<<endl;
    }
    cout<<"-----------------"<<endl;
    vector<int> ans4 = nextSmallerOnLeft(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" -> "<<ans4[i]<<endl;
    }
    return 0;
}