#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to create a new node with given data
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top; // Pointer to the top node of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value in case of an empty stack
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    // Function to get the top element of the stack
    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value in case of an empty stack
        }
        return top->data;
    }

    // Function to get the size of the stack
    int size() {
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
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
