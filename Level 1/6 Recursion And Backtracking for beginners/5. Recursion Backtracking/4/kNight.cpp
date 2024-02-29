#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
void knight(vector<vector<int>> board,int r,int c, int move){
    if(r<0 or c<0 or r>=board.size() or c>=board.size() or board[r][c]>0){
        return;
    }else if(move==board.size()*board.size()){
        board[r][c]=move;
        display(board);
        board[r][c]=0;
        return;
    }
    board[r][c]=move;
    knight(board,r-2,c+1,move+1);
    knight(board,r-1,c+2,move+1);
    knight(board,r+1,c+2,move+1);
    knight(board,r+2,c+1,move+1);
    knight(board,r+2,c-1,move+1);
    knight(board,r+1,c-2,move+1);
    knight(board,r-1,c-2,move+1);
    knight(board,r-2,c-1,move+1);
    board[r][c]=0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    int r,c;
    cin>>r>>c;
    knight(board,r,c,1);
    return 0;
}
