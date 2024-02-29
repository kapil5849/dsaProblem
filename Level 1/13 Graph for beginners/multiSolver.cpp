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
struct myComp{
    bool operator()(
        pair<int,string> & a,
        pair<int,string> & b
    )
    {
        return a.first > b.first;
    }
};
string sPath;
int sPathWt = INT_MAX;
string lPath;
int lPathWt = INT_MIN;
string cPath;
int cPathWt = INT_MAX;
string fPath;
int fPathWt = INT_MIN;
priority_queue<pair<int,string>,vector<pair<int,string>>,myComp> pq;
void multiSolver(vector<Edge> graph[],int src,int dest,vector<bool> visited,int criteria,int k,string psf,int wsf){
    if(src==dest){
        if(wsf<sPathWt){
            sPath=psf;
            sPathWt=wsf;
        }
        if(wsf>lPathWt){
            lPathWt=wsf;
            lPath=psf;
        }
        if(wsf>criteria and wsf<cPathWt){
            cPathWt=wsf;
            cPath=psf;
        }
        if(wsf<criteria and wsf>fPathWt){
            fPathWt=wsf;
            fPath=psf;
        }
        pair<int,string> p;
        p.first=wsf;
        p.second=psf;
        pq.push(p);
        if(pq.size()>k){
            pq.pop();
        }
        return;
    }
    visited[src]=true;
    for(Edge edge:graph[src]){
        if(visited[edge.nbr]==false){
            multiSolver(graph,edge.nbr,dest,visited,criteria,k,psf+to_string(edge.nbr),wsf+edge.wt);
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
    int src,dest;
    cin>>src>>dest;
    int criteria;
    cin>>criteria;
    int k;
    cin>>k;
    vector<bool> visited(vtc,false);
    multiSolver(graph,src,dest,visited,criteria,k,src+"0",0);
    cout << "Smallest Path = " << sPath << "@" << sPathWt << endl;
    cout << "Largest Path = " << lPath << "@" << lPathWt << endl;
    cout << "Just Larger Path than " << criteria << " = " << cPath << "@" << cPathWt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << fPath << "@" << fPathWt << endl;
    cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;
    return 0;
}
