#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src=0,nbr=0;
    Edge(int src,int nbr){
        this->src=src;
        this->nbr=nbr;
    }
};
class Pair{
    public:
    int src =0;
    string psf="";
    int level =0;
    Pair(int src,string psf,int level){
        this->src=src;
        this->psf=psf;
        this->level=level;
    }
};
bool checkComponentBiPartiteNess(vector<vector<Edge>> graph,int src,vector<int> visited){
    queue<Pair> q;
    q.push(Pair(src,to_string(src)+"",0));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        if(visited[rem.src]!=-1){
            if(rem.level!=visited[rem.src]){
                return false;
            }
        }
        else{
            visited[rem.src]=rem.level;
        }
        for(Edge e:graph[rem.src]){
            if(visited[e.nbr]==-1){
                q.push(Pair(e.nbr,rem.psf+to_string(e.nbr),rem.level+1));
            }
        }
    }
    return true;
}
int main(){
    int vtc,edges;
    cin>>vtc>>edges;
    vector<vector<Edge>> graph(vtc,vector<Edge>());
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(Edge(u,v));
        graph[v].push_back(Edge(v,u));
    }
    vector<int> visited(vtc,-1);
    for(int v=0;v<vtc;v++){
        if(visited[v]==-1){
            bool isCompBiPartite=checkComponentBiPartiteNess(graph,v,visited);
            if(isCompBiPartite==false){
                cout<<"false"<<endl;
                return 0;
            }
        }
    }
    cout<<"true"<<endl;
    return 0;
}
