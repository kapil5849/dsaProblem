#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    vector<int> arr;  // Using vector instead of dynamic array

    // Constructor
    Stack() {}

    // Function to check if the stack is full
    bool isFull() {
        // Assuming vectors can always grow
        return false;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return arr.empty();
    }

    // Function to push an element onto the stack
    void push(int x) {
        arr.push_back(x);
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value in case of an empty stack
        }
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    // Function to get the top element of the stack
    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value in case of an empty stack
        }
        return arr.back();
    }

    // Function to get the size of the stack
    int size() {
        return arr.size();
    }
};

int main() {
    Stack st;
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
