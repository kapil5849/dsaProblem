#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int inc = arr[0];
    int exc = 0;
    for(int i=1;i<n;i++){
        int newInc = exc+arr[i];
        int newExc = max(inc,exc);
        inc = newInc;
        exc = newExc;
    }
    cout<<max(exc,inc)<<endl;
    return 0;
}

// 6
// 5
// 10
// 10
// 100
// 5
// 6