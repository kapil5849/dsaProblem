#include<bits/stdc++.h>
using namespace std;
void floodFill(vector<vector<int>> arr,int row, int col,string ans,vector<vector<bool>> visited){
    if(row<0 or col<0 or row==arr.size() or col==arr[0].size() or arr[row][col]==1 or visited[row][col]==true){
        return;
    }
    if(row==arr.size()-1 and col==arr[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    visited[row][col]=true;
    floodFill(arr,row-1,col,ans+"t",visited);
    floodFill(arr,row,col-1,ans+"l",visited);
    floodFill(arr,row+1,col,ans+"d",visited);
    floodFill(arr,row,col+1,ans+"r",visited);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    floodFill(arr,0,0,"",visited);
    return 0;
}