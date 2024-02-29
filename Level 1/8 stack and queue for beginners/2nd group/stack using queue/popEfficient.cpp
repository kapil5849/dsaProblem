#include <iostream>
#include <queue>

using namespace std;

class StackPopEfficient {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Function to push an element onto the stack
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Enqueue the new element to q1
        q1.push(x);

        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Return a default value in case of an empty stack
        }

        // Pop the front element from q1
        int poppedElement = q1.front();
        q1.pop();

        return poppedElement;
    }

    // Function to get the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Return a default value in case of an empty stack
        }

        return q1.front();
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackPopEfficient stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.push(4);
    stack.push(5);

    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << endl;
    }

    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}
