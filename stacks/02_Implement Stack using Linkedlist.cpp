class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    // Push element onto stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop top element
    int pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    // Peek top element
    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }
};

