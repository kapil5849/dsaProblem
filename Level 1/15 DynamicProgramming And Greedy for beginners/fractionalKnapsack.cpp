#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> value(n,0);
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    vector<int> weight(n,0);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int cap;
    cin>>cap;
    multimap<double,int> mpp;
    double ans = 0.0;
    for(int i=0;i<n;i++){
        double ratio = (double)value[i]/weight[i];
        mpp.insert(make_pair(ratio,i));
    }
    multimap<double,int>::reverse_iterator itr;
    for(itr=mpp.rbegin();itr!=mpp.rend();itr++){
        double wt = weight[itr->second];
        double val = value[itr->second];
        if(cap>=wt){
            cap-=wt;
            ans+=val;
        }
        else if(cap<wt){
            double frac = cap/wt;
            ans+=frac*val;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

// 3 
// 60 100 120 
// 10 20 30
// 50