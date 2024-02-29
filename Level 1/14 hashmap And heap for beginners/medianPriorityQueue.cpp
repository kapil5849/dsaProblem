#include<bits/stdc++.h>
using namespace std;
class MedianPriorityQueue{
    public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    void push(int val){
        if(size()==0){
            left.push(val);
        }
        else if (right.size()>0 and val>right.top()){
            right.push(val);
        }
        else{
            left.push(val);
        }
        if(left.size()-right.size()==2){
            int value = left.top();
            left.pop();
            right.push(value);
        }
        else if(right.size()-left.size()==2){
            int value = right.top();
            right.pop();
            left.push(value);
        }
    }
    int pop(){
        if(size()==0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        if(left.size()>=right.size()){
            int value=left.top();
            left.pop();
            return value;
        }
        else{
            int value=right.top();
            right.pop();
            return value;
        }
    }
    int top(){
        if(size()==0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        if(left.size()>=right.size()){
            return left.top();
        }
        else{
            return right.top();
        }
    }
    int size(){
        return left.size()+right.size();
    }
};
int main(){
    MedianPriorityQueue pq;
    string str;
    cin>>str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin>>val;
            pq.push(val);
        }
        else if(str=="remove"){
            int val=pq.pop();
            if(val!=-1){
                cout<<val<<endl;
            }
        }
        else if(str=="peek"){
            int val=pq.top();
            if(val!=-1){
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<pq.size()<<endl;
        }
        cin>>str;
    }
    return 0;
}