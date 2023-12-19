#include<bits/stdc++.h>
using namespace std;
void printPath(int n,string path){
    if(n==0){
        cout<<path<<endl;
        return;
    }
    if(n>=1){
        printPath(n-1,path+"1");
    }
    if(n>=2){
        printPath(n-2,path+"2");
    }
    if(n>=3){
        printPath(n-3,path+"3");
    }
}
int main(){
    int n;
    cin>>n;
    printPath(n,"");
    return 0;
}