// Reverse using a Stack (Brute Force)
// 1. Push all node values into a stack.
// 2. Pop and overwrite node values.
// Time Complexity: O(N)
// Space Complexity: O(N)
Node* reverseUsingStack(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    stack<int> st;
    Node* temp = head;

    // Step 1: Push all values into stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Step 2: Reassign values from stack
    temp = head;
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// Reverse using Iterative Pointer Approach (Optimal)
// Reverses links by maintaining three pointers: prev, temp, and front.
// Time Complexity: O(N)
// Space Complexity: O(1)
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* temp = head;

    while (temp != nullptr) {
        Node* front = temp->next; // Store next node
        temp->next = prev;        // Reverse current link
        prev = temp;              // Move prev forward
        temp = front;             // Move temp forward
    }

    return prev; // New head of the reversed list
}
