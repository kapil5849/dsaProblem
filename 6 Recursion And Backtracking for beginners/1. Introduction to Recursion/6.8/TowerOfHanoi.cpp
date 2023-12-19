#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, int source, int auxiliary, int destination){
    if(n==1){
        cout<<n<<"["<<source<<" -> "<<destination<<"]"<<endl;
        return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    cout<<n<<"["<<source<<" -> "<<destination<<"]"<<endl;
    towerOfHanoi(n-1,auxiliary,source,destination);
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int tower1=1,tower2=2,tower3=3;
    towerOfHanoi(n,tower1,tower2,tower3);
    return 0;
}