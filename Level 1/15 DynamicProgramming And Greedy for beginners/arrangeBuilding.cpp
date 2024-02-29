#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ob = 1;
    int os = 1;
    for(int i=2;i<=n;i++){
        int nb = os;
        int ns = ob+os;
        ob=nb;
        os=ns;
    }
    int answer = ob+os;
    cout<<(answer*answer)<<endl;
}