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
void drawTreeAndCreateComp(vector<vector<Edge>> graph,int src,vector<int> &comp,vector<bool> & visited){
    visited[src]=true;
    comp.push_back(src);
    for(Edge e:graph[src]){
        if(visited[e.nbr]==false){
            drawTreeAndCreateComp(graph,e.nbr,comp,visited);
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<Edge>> graph(n,vector<Edge>());
    for(int e=0;e<k;e++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(Edge(v1,v2));
        graph[v2].push_back(Edge(v2,v1));
    }
    vector<bool> visited(n,false);
    vector<vector<int>> comps;
    for(int v=0;v<n;v++){
        if(visited[v]==false){
            vector<int> comp;
            drawTreeAndCreateComp(graph,v,comp,visited);
            comps.push_back(comp);
        }
    }
    int pairs=0;
    for(int i=0;i<comps.size();i++){
        for(int j=i+1;j<comps.size();j++){
            int cnt = comps[i].size()*comps[j].size();
            pairs+=cnt;
        }
    }
    cout<<pairs<<endl;
    return 0;
}


