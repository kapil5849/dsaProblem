#include<iostream>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t){
        cin>>n;
        int cnt=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                break;
            }
        }
        if(cnt==0){
            cout<<"prime"<<endl;
        }else{
            cout<<"not prime"<<endl;
        }
        t--;
    }
    return 0;
}
