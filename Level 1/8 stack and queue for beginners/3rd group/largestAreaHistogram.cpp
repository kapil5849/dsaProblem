// 7 6 2 5 4 5 1 6 
// 12
// time complexity : O(n)
// space complexity : O(n)

#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerLeft(vector<int> arr){
    int n = arr.size();
    vector<int> nsl(n,0);
    stack<int> st;
    nsl[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 and arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.size()==0){
            nsl[i]=-1;
        }else{
            nsl[i]=st.top();
        }
        st.push(i);
    }
    return nsl;
}
vector<int> nextSmallerRight(vector<int> arr){
    int n = arr.size();
    vector<int> nsr(n,0);
    stack<int> st;
    nsr[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.size()==0){
            nsr[i]=n;
        }else{
            nsr[i]=st.top();
        }
        st.push(i);
    }
    return nsr;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxArea = INT_MIN;
    vector<int> lb = nextSmallerLeft(arr);
    vector<int> rb = nextSmallerRight(arr);
    for(int i=0;i<n;i++){
        int area = arr[i]*(rb[i]-lb[i]-1);
        if(area>maxArea){
            maxArea=area;
        }
    }
    cout<<maxArea<<endl;
    return 0;
}