#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;
vector<int> mergeKSortedLists(vector<vector<int>> &lists){
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    vector<int> rv;
    for(int i=0;i<lists.size();i++){
        pq.push({lists[i][0],{i,0}});
    }
    while(pq.size()>0){
        pp value = pq.top();
        pq.pop();
        int idx = value.second.second;
        int listNumber = value.second.first;
        rv.push_back(value.first);
        if(idx+1<lists[listNumber].size()){
            pq.push({lists[listNumber][idx+1],{listNumber,idx+1}});
        }
    }
    return rv;
}
int main(){
    int k;
    cin>>k;
    vector<vector<int>> lists;
    for(int i=0;i<k;i++){
        vector<int>list;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int data;
            cin>>data;
            list.push_back(data);
        }
        lists.push_back(list);
    }
    vector<int> mlist = mergeKSortedLists(lists);
    for(int val:mlist){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}

