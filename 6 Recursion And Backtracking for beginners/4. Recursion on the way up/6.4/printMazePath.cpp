#include<bits/stdc++.h>
using namespace std;
void printPath(int sr,int sc,int dr,int dc,string path){
    if(sr==dr and sc==dc){
        cout<<path<<endl;
        return;
    }
    if(sc<dc){
        printPath(sr,sc+1,dr,dc,path+"h");
    }
    if(sr<dr){
        printPath(sr+1,sc,dr,dc,path+"v");
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    printPath(1,1,n,m,"");
    return 0;
}