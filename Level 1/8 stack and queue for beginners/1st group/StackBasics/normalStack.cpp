#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
    int maxSize; // n
    int top; // -1
    int *arr; // Fixed array declaration

    // Public constructor
    public:
    Stack(int n) {
        maxSize = n;
        top = -1;
        arr = new int[maxSize];
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value in case of an empty stack
        }
        int val = arr[top];
        top--;
        return val;
    }

    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value in case of an empty stack
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "size: " << st.size() << endl;
    st.push(4);
    st.push(5);
    cout << "size: " << st.size() << endl;
    cout << "top: " << st.getTop() << endl;
    cout << "full or not: " << st.isFull() << endl;
    st.push(6);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << "size: " << st.size() << endl;
    cout << "empty or not: " << st.isEmpty() << endl;
    cout << st.pop() << endl;

    return 0;
}
