#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data,Node * left,Node * right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * root = construct(arr);
    display(arr);
    return 0;
}