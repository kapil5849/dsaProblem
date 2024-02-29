#include<bits/stdc++.h>
using namespace std;
bool queenSafe(vector<vector<int>> board,int row,int col){
    for(int i=row-1,j=col;i>=0;i--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 and j<board[0].size();i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void nQueen(vector<vector<int>> board,int row,string qsf){ // qsf: queen so far
    if(row==board.size()){
        cout<<qsf<<"."<<endl;
        return;
    }  
    for(int col=0;col<board.size();col++){
        if(queenSafe(board,row,col)==true){
            board[row][col]=1;
            nQueen(board,row+1,qsf+to_string(row)+"-"+to_string(col)+", ");
            board[row][col]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));  
    nQueen(board,0,"");
    return 0;
}
