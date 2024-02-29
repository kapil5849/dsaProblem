#include<bits/stdc++.h>
using namespace std;
void printPath(int sr,int sc,int dr,int dc,string path){
    if(sr==dr && sc==dc){
        cout<<path<<endl;
        return;
    }
    for(int hms=1;sc+hms<=dc;hms++){
        printPath(sr,sc+hms,dr,dc,path+"h"+to_string(hms));
    }
    for(int vms=1;sr+vms<=dr;vms++){
        printPath(sr+vms,sc,dr,dc,path+"v"+to_string(vms));
    }
    for(int dms=1;sr+dms<=dr && sc+dms<=dc;dms++){
        printPath(sr+dms,sc+dms,dr,dc,path+"d"+to_string(dms));
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    printPath(1,1,n,m,"");
    return 0;
}