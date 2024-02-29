#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
    vector<int> arr;
    public:
    bool isEmpty(){
        return arr.size()==0; // arr.empty()... 
    }
    bool isFull(){
        return false;
    }
    int size(){
        return arr.size();
    }
    void enqueue(int x){
        arr.push_back(x);
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int value = arr.front();
        arr.erase(arr.begin());
        return value;
    }
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr.front();
    }
};
int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.enqueue(4);
    q.enqueue(5);

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    cout << "Front element after dequeue: " << q.getFront() << endl;
    return 0;
}