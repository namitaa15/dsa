class MinStack {
    stack<int> st;
    stack<int> minSt; // stores the current minimum

public:
    MinStack() { }

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val); // push to min stack only if it's new min
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop(); // remove from min stack too
        }
        st.pop();
    }

    int top() {
        if (st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top(); // minimum in O(1)
    }
};
