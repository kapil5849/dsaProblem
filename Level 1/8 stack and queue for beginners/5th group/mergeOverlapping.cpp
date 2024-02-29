#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> &a,vector<int> &b){
    return a[0]<b[0];
}
void mergeOverlapping(vector<vector<int>> &intervals){
    sort(intervals.begin(),intervals.end(),compare);
    stack<vector<int>> st;
    st.push(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        vector<int> cm = intervals[i];
        vector<int> lm = st.top();
        if(lm[1]>=cm[0]){
            st.pop();
            vector<int> merge = {lm[0],max(lm[1],cm[1])};
            st.push(merge);
        }else{
            st.push(cm);
        }
    }
    stack<vector<int>> st1;
    while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    while(!st1.empty()){
        vector<int> temp = st1.top();
        cout<<temp[0]<<" - "<<temp[1]<<endl;
        st1.pop();
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    mergeOverlapping(intervals);
    return 0;
}