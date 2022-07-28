#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int nbr;
    int wt;
    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};
void hamiltonianPathAndCycle(vector<Edge> graph[],int oSrc,int src,vector<bool> visited,string psf){
    if(visited.size() == graph.size-1){
        cout<<psf<<endl;
        bool closingEdge =false;
        for(Edge e:graph[oSrc]){
            if(e.nbr==src){
                closingEdge=true;
                break;
            }
        }
        if(closingEdge){
            cout<<"*"<<endl;
        }
        else{
            cout<<"."<<endl;
        }
        return;
    }
    visited[src]=true;
    for(Edge e:graph[src]){
        if(visited[e.nbr]==false){
            hamiltonianPathAndCycle(graph,oSrc,e.nbr,visited,psf);
        }
    }
    visited[src]=false;
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
    int src;
    cin>>src;
    vector<bool> visited(vtc,false);
    hamiltonianPathAndCycle(graph,src,src,visited,src+"");
    return 0;
}

// 7
// 9
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
// 2 5 10
// 0