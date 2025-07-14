#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue (costly): push element at the end
    void enqueue(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element onto s1
        s1.push(x);

        // Push everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue: remove from front
    int dequeue() {
        if (s1.empty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int front = s1.top();
        s1.pop();
        return front;
    }

    // Peek: front element
    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    // Check if empty
    bool isEmpty() {
        return s1.empty();
    }
};
