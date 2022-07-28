#include <bits/stdc++.h>
using namespace std;
void drawTreeForIslands(vector<vector<int>>& arr,int i,int j,vector<vector<bool>>& visited){
    if(i<0 or j<0 or i>=visited.size() or j>=visited[0].size() or arr[i][j]==1 or visited[i][j]==true){
        return;
    }
    visited[i][j]=true;
    drawTreeForIslands(arr,i-1,j,visited);
    drawTreeForIslands(arr,i+1,j,visited);
    drawTreeForIslands(arr,i,j-1,visited);
    drawTreeForIslands(arr,i,j+1,visited);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        vector<int> ans;
        for(int j=0;j<m;j++){
            int res;
            cin>>res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0 and visited[i][j]==false){
                drawTreeForIslands(arr,i,j,visited);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

