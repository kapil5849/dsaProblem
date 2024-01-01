#include<iostream>
using namespace std;   
int main(){
    int n;
    cin>>n;
    int val = 1;
    for(int i=n;i>=1;i--){
        int cval = val;
        for(int j=1;j<=i;j++){
            if(i>1 and i<n and j>1 and j<i){
                cout<<"  ";
            }else{
                cout<<cval<<" ";
            }
            cval++;
        }
        val++;
        cout<<endl;
    }
    return 0;
}
