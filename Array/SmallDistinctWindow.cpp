#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findSubString(string str){
        set<int> s;
        for(char ch:str){
            s.insert(ch);
        }
        int i=0,j=0,ans=str.size();
        unordered_map<char,int> mpp;
        while(i<str.size()){
            mpp[str[i]]++;
            if(s.size()==mpp.size()){
                while(mpp[str[j]]>1){
                    mpp[str[j]]--;
                    j++;
                }
                ans=min(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}