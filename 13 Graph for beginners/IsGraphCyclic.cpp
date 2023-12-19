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
    int src=0;
    string psf = "";
    Pair(int src,string psf){
        this->src=src;
        this->psf=psf;
    }
};
bool isCycle(vector<vector<Edge>>graph,int src,vector<bool> visited){
    queue<Pair> q;
    q.push(Pair(src,to_string(src)+""));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        if(visited[rem.src]==true){
            return true;
        }
        visited[rem.src]=true;
        for(Edge e:graph[rem.src]){
            if(visited[e.nbr]==false){
                q.push(Pair(e.nbr,rem.psf+to_string(e.nbr)));
            }
        }
    }
    return false;
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
    vector<bool> visited(vtc,false);
    for(int v=0;v<vtc;v++){
        if(visited[v]==false){
            bool cycle = isCycle(graph,v,visited);
            if(cycle){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
    return 0;
}