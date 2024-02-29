#include<bits/stdc++.h>
using namespace std;
int main(){
    int low,high;
    cin>>low>>high;
    for(int i=low;i<=high;i++){
        int cnt=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                cnt++;
            }
        }
        if(cnt==0){
            cout<<i<<endl;
        }
    }
    return 0;
}

