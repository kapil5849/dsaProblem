#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> &arr){
    int one = 0,two = 0,three = INT_MAX;
    for(int i=0;i<arr.size();i++){
        int maskOne = one & arr[i];
        int maskTwo = two & arr[i];
        int maskThree = three & arr[i];
        int none = one & (~maskOne);
        none = none | maskThree;
        int ntWo = two & (~maskTwo);
        ntWo = ntWo | maskOne;
        int nThree = three & (~maskThree);
        nThree = nThree | maskTwo;
        one = none;
        two = ntWo;
        three = nThree;
    }
    return one;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solution(arr)<<endl;
    return 0;
}