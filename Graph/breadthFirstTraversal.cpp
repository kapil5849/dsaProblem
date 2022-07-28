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
    int src;
    cin>>src;
    vector<bool> visited(vtc,false);
    queue<Pair> q;
    q.push(Pair(src,to_string(src)+""));
    while(q.size()>0){
        Pair temp = q.front();
        q.pop();
        if(visited[temp.src]==true){
            continue;
        }
        visited[temp.src]=true;
        cout<<temp.src<<"@"<<temp.psf<<endl;
        for(Edge edge:graph[temp.src]){
            if(visited[edge.nbr]==false){
                q.push(Pair(edge.nbr,temp.psf+to_string(edge.nbr)));
            }
        }
    }
    return 0;
}