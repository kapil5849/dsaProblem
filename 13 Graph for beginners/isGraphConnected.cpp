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
void drawAndGenerateTree(vector<Edge> graph[],int src,vector<int> &comp,vector<bool> &visited){
    visited[src]=true;
    comp.push_back(src);
    for(Edge e:graph[src]){
        if(visited[e.nbr]==false){
            drawAndGenerateTree(graph,e.nbr,comp,visited);
        }
    }
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
    vector<vector<int>> comps;
    vector<bool> visited(vtc,false);
    for(int v=0;v<vtc;v++){
        if(visited[v]==false){
            vector<int> comp;
            drawAndGenerateTree(graph,v,comp,visited);
            comps.push_back(comp);
        }
    }
    if(comps.size()==1){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}

