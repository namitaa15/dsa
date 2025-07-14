#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    // Push element onto stack (costly push)
    void push(int x) {
        q2.push(x);

        // Push all elements of q1 into q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Remove top element
    int pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int top = q1.front();
        q1.pop();
        return top;
    }

    // Get top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};
