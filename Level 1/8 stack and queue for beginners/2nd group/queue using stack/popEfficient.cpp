#include<bits/stdc++.h>
using namespace std;
class popEfficient{
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
        while(s1.size()>0){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        s1.push(val);
        while(s2.size()>0){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
    }
    int pop(){
        if(size()==0){
            cout<<"Queue is empty or underflow"<<endl;
            return -1;
        }
        int value = s1.top();
        s1.pop();
        return value;
    }
    int front(){
        if(size()==0){
            cout<<"Queue is empty or underflow"<<endl;
            return -1;
        }
        return s1.top();
    }
};
int main(){
    popEfficient q;
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