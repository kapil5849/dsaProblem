#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
    int maxSize,front,rear;
    int *arr;
    public:
    Queue(int n){
        maxSize=n;
        front=-1;
        rear=-1;
        arr = new int[maxSize];
    }
    ~Queue(){
        delete[] arr;
    }
    bool isEmpty(){
        return front==-1 and rear==-1;
    }
    bool isFull(){
        return rear==maxSize-1;
    }
    int size(){
        if(isEmpty()){
            return 0;
        }
        return rear-front+1;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        else if(isEmpty()){
            front++;
            rear++;
            arr[rear]=x;
        }
        else{
            rear++;
            arr[rear]=x;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        else if(front==rear){
            int value = arr[front];
            front=-1;
            rear=-1;
            return value;
        }
        else{
            int value = arr[front];
            front++;
            return value;
        }
    }
    int getFront(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return arr[front];
    }
};
int main(){
    Queue q(5);

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