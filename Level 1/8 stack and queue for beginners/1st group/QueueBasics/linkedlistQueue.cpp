#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};
class Queue{
    private:
    Node* front;
    Node* rear;
    public:
    Queue():front(nullptr),rear(nullptr){}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    bool isEmpty(){
        return front==nullptr;
    }
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(isEmpty()){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        if(front==rear){
            front=rear=nullptr;
        }else{
            front=front->next;
        }
        return val;
    }
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
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