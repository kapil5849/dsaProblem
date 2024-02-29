#include<bits/stdc++.h>
using namespace std;
class minStack{
    private:
    stack<int> allData;
    stack<int> minData;
    public:
    void push(int val){
        allData.push(val);
        if(minData.size()==0 or val<=minData.top()){
            minData.push(val);
        }
    }
    int pop(){
        if(allData.size()==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        int val = allData.top();
        allData.pop();
        if(val==minData.top()){
            minData.pop();
        }
        return val;
    }
    int top(){
        if(allData.size()==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return allData.top();
    }
    int getMin(){
        if(minData.size()==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return minData.top();
    }
    int size(){
        return allData.size();
    }
};
int main(){
    minStack st;
    st.push(10);
    st.push(20);
    st.push(5);
    st.push(8);
    st.push(2);
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    cout<<"min: "<<st.getMin()<<endl;
    cout<<"pop: "<<st.pop()<<endl;
    cout<<"min after pop: "<<st.getMin()<<endl;
    cout<<"top: "<<st.top()<<endl;
    return 0;
}