#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src,nbr,wt;
    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};
bool hasPath(vector<Edge> graph[],int src,int dest,vector<bool> visited){
    if(src==dest){
        return true;
    }
    visited[src]=true;
    for(Edge edge:graph[src]){
        if(visited[edge.nbr]==false and hasPath(graph,edge.nbr,dest,visited)){
            return true;
        }
    }
    return false;
}
int main(){
    int vtc,edges;
    cin>>vtc>>edges;
    vector<Edge> graph[vtc];
    for(int i=0;i<edges;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(Edge(v1,v2,wt));
        graph[v2].push_back(Edge(v2,v1,wt));
    }
    int src,dest;
    cin>>src>>dest;
    vector<bool> visited(vtc,false);
    if(hasPath(graph,src,dest,visited)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}

