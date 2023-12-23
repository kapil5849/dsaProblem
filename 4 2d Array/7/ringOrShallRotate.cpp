#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr){
    int i,j;
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void reverse(vector<int> &oned,int i,int j){
    while(i<j){
        int temp = oned[i];
        oned[i] = oned[j];
        oned[j] = temp;
        i++;
        j--;
    }
}
void rotate(vector<int> &oned,int r){
    int n = oned.size();
    r = r%n;
    if(r<0){
        r = r+n;
    }
    reverse(oned,0,n-r-1);
    reverse(oned,n-r,n-1);
    reverse(oned,0,n-1);
}
vector<int> filled1DFromShall(vector<vector<int>> &arr,int s){
    int minr = s-1;
    int minc = s-1;
    int maxr = arr.size()-s;
    int maxc = arr[0].size()-s;
    int size = 2*(maxr-minr+maxc-minc);
    vector<int> oned(size);
    int idx = 0;
    // left wall
    for(int i = minr,j=minc;i<=maxr;i++){
        oned[idx]=arr[i][j];
        idx++;
    }
    // bottom wall
    for(int i = maxr,j=minc+1;j<=maxc;j++){
        oned[idx]=arr[i][j];
        idx++;
    }
    // right wall
    for(int i = maxr-1,j=maxc;i>=minr;i--){
        oned[idx]=arr[i][j];
        idx++;
    }
    // top wall
    for(int i = minr,j=maxc-1;j>=minc+1;j--){
        oned[idx]=arr[i][j];
        idx++;
    }
    return oned;
}
void fillShallFrom1D(vector<vector<int>> &arr,int s,vector<int> &oned){
    int minr = s-1;
    int minc = s-1;
    int maxr = arr.size()-s;
    int maxc = arr[0].size()-s;
    int idx = 0;
    // left wall
    for(int i = minr,j=minc;i<=maxr;i++){
        arr[i][j]=oned[idx];
        idx++;
    }
    // bottom wall
    for(int i = maxr,j=minc+1;j<=maxc;j++){
        arr[i][j]=oned[idx];
        idx++;
    }
    // right wall
    for(int i = maxr-1,j=maxc;i>=minr;i--){
        arr[i][j]=oned[idx];
        idx++;
    }
    // top wall
    for(int i = minr,j=maxc-1;j>=minc+1;j--){
        arr[i][j]=oned[idx];
        idx++;
    }
} 
void rotateShall(vector<vector<int>> & arr,int s,int r){
    vector<int> oned = filled1DFromShall(arr,s);
    rotate(oned,r);
    fillShallFrom1D(arr,s,oned);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int s,r;
    cin>>s>>r;
    rotateShall(arr,s,r);
    display(arr);
    return 0;
}