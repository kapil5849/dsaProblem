#include<bits/stdc++.h>
using namespace std;
class TwoStacks{
    private:
    int maxSize,top1,top2;
    int *arr;
    public:
    TwoStacks(int n){
        maxSize=n;
        top1=-1;
        top2=maxSize;
        arr = new int[maxSize];
    }
    int size1(){
        return top1+1;
    }
    int size2(){
        return maxSize-top2;
    }
    void push1(int x){
        if(size1()+size2()==maxSize){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1]=x;
        }
    }
    void push2(int x){
        if(size1()+size2()==maxSize){
            cout<<"Stack Overflow"<<endl;
        }else{
            top2--;
            arr[top2]=x;
        }
    }
    int pop1(){
        if(top1==-1){
            cout<<"Stack Underflow"<<endl;
        }else{
            int value = arr[top1];
            top1--;
            return value;
        }
    }
    int pop2(){
        if(top2==maxSize){
            cout<<"Stack Underflow"<<endl;
        }else{
            int value = arr[top2];
            top2++;
            return value;
        }
    }
    int getTop1(){
        if(top1==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top1];
    }
    int getTop2(){
        if(top2==maxSize){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top2];
    }
};
int main(){
    TwoStacks ts(5);

    ts.push1(1);
    ts.push2(2);
    ts.push1(3);
    ts.push2(4);
    ts.push1(5);

    // cout<<"check:"<<endl;
    // ts.push1(6);
    // ts.push2(7);
    
    cout<<"size of stack 1: "<<ts.size1()<<endl;
    cout<<"size of stack 2: "<<ts.size2()<<endl;
    cout<<"Top element of stack 1: "<<ts.getTop1()<<endl;
    cout<<"Top element of stack 2: "<<ts.getTop2()<<endl;

    cout << "Popped from stack 1: " << ts.pop1() << endl;
    cout << "Popped from stack 2: " << ts.pop2() << endl;

    cout<<"Top element of stack 1: "<<ts.getTop1()<<endl;
    cout<<"Top element of stack 2: "<<ts.getTop2()<<endl;

    cout << "Popped from stack 1: " << ts.pop1() << endl;
    cout << "Popped from stack 2: " << ts.pop2() << endl;
    cout << "Popped from stack 1: " << ts.pop1() << endl;

    return 0;
}