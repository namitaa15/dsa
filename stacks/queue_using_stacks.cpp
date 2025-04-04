class MyQueue {
public:
    stack<int> input, output;

    MyQueue() {
        // Constructor: Nothing to initialize here
    }

    void push(int x) {
        input.push(x);  // Always push to input stack
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int topVal = output.top();
        output.pop();
        return topVal;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};
