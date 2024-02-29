#include<bits/stdc++.h>
using namespace std;
int wordMask(string &word){
    int mask = 0;
    for(auto c:word){
        mask = mask | 1<<(c-'a');
    }
    return mask;
}
vector<int> solution(vector<string> &words,vector<string> &puzzles){
    unordered_map<int,int> mpp;
    for(auto word:words){
        mpp[wordMask(word)]++;
    }
    vector<int> ans;
    for(auto p:puzzles){
        int mask = wordMask(p);
        int submask=mask;
        int first = (1<<(p[0]-'a'));
        int curr = 0;
        while(submask){
            if(submask & first){
                curr+=mpp[submask];
            }
            submask = (submask-1) & mask;
        }
        ans.push_back(curr);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    cin>>m;
    vector<string> puzzles(m);
    for(int i=0;i<m;i++){
        cin>>puzzles[i];
    }
    vector<int> ans=solution(words,puzzles);
    for(int i=0;i<m;i++){
        cout<<puzzles[i]<<"->"<<ans[i]<<endl;
    }
    return 0;
}