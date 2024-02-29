#include<bits/stdc++.h>
using namespace std;
class pushEfficient{
    private:
    stack<int> s1;
    stack<int> s2;
    public:
    int size(){
        return s1.size();
    }
    bool empty(){
        return s1.empty();
    }
    void push(int val){
        s1.push(val);
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty or underflow"<<endl;
            return -1;
        }
        while(s1.size()>0){
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int value = s2.top();
        s2.pop();
        while(s2.size()>0){
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
        return value;
    }
    int front(){
        if(s1.empty()){
            cout<<"Queue is empty or underflow"<<endl;
            return -1;
        }
        while(s1.size()>0){
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int value = s2.top();
        while(s2.size()>0){
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
        return value;
    }
};
int main(){
    pushEfficient q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.front()<<endl;
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}