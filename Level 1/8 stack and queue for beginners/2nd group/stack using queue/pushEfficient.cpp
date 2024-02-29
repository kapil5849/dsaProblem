#include <iostream>
#include <queue>

using namespace std;

class StackPushEfficient {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Function to push an element onto the stack
    void push(int x) {
        // Enqueue the new element to q1
        q1.push(x);
    }

    // Function to pop the top element from the stack
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Return a default value in case of an empty stack
        }

        // Move all elements from q1 to q2 except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the last element from q1
        int poppedElement = q1.front();
        q1.pop();

        // Swap the names of q1 and q2
        swap(q1, q2);

        return poppedElement;
    }

    // Function to get the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Return a default value in case of an empty stack
        }

        return q1.back();
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackPushEfficient stack;

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
