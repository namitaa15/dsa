class Queue {
    int front, rear;
    int arr[1000];  // Max size

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    // Enqueue: insert element at rear
    void enqueue(int x) {
        if (rear == 1000) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rear++] = x;
    }

    // Dequeue: remove element from front
    int dequeue() {
        if (front == rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    // Peek front element
    int peek() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == rear;
    }
};
