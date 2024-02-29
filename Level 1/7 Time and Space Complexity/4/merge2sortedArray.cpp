#include<bits/stdc++.h>
using namespace std;
vector<int> mergeTwoSortedArray(vector<int> & a, vector<int> & b){
    int i=0,j=0,k=0;
    vector<int> c(a.size()+b.size());
    while(i<a.size() and j<b.size()){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<a.size()){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<b.size()){
        c[k]=b[j];
        j++;
        k++;
    }
    return c;
}
int main(){
    int n,m;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> c(n+m);
    c = mergeTwoSortedArray(a,b);
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<", ";
    }
    return 0;
}