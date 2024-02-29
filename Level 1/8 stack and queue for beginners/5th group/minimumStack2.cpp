#include<bits/stdc++.h>
using namespace std;
class minStack{
    private:
    stack<int> allData;
    int minData;
    public:
    int size(){
        return allData.size();
    }
    void push(int val){
        if(allData.size()==0){
            allData.push(val);
            minData = val;
        }else if(val>=minData){
            allData.push(val);
        }else{
            allData.push(2*val-minData);
            minData = val;
        }
    }
    int pop(){
        if(allData.size()==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        int val = allData.top();
        allData.pop();
        if(val<minData){
            int originalVal = minData;
            minData = 2*minData-val;
            return originalVal;
        }
        return val;
    }
    int top(){
        if(allData.size()==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        if(allData.top()<minData){
            return minData;
        }
        return allData.top();
    }
    int getMin(){
        if(allData.size()==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return minData;
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