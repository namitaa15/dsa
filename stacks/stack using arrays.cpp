class Stack {
    int top;
    int arr[1000];  // Max size of stack

public:
    Stack() {
        top = -1;  // Stack is empty initially
    }

    // Push element to the stack
    void push(int x) {
        if (top >= 999) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // Pop element from the stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Get top element
    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};
