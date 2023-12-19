#include<bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int> &num) {
    unordered_map<int,bool> mpp;
    for(int i=0;i<num.size();i++){
        mpp[num[i]]=true;
    }
    for(int i=0;i<num.size();i++){
        if(mpp.find(num[i]-1)!=mpp.end()){
            mpp[num[i]]=false;
        }
    }
    int msp=0;
    int ml=0;
    for(auto val:num){
        if(mpp[val]==true){
            int tsp=val;
            int tl=1;
            while(mpp.find(tsp+tl)!=mpp.end()){
                tl++;
            }
            if(tl>ml){
                ml=tl;
                msp=tsp;
            }
        }
    }
    for(int i=0;i<ml;i++){
        cout<<msp+i<<endl;
    }
}
int main(){
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  longestConsecutive(arr);
  return 0;
}
