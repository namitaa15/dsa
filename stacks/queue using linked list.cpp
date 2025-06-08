class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue: insert at rear
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue: remove from front
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int val = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;

        delete temp;
        return val;
    }

    // Peek: front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }
};
