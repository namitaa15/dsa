/*
✅ Leetcode - Remove N-th Node From End of Linked List

📄 Given the head of a linked list and an integer N,
remove the N-th node from the end and return the modified head.

🧠 Approach:
- Use a dummy node before head to simplify edge cases.
- Move a fast pointer N steps ahead.
- Move both fast and slow pointers until fast reaches end.
- Now, slow is just before the N-th node from the end.
- Skip that node using: slow->next = slow->next->next

📈 Time Complexity: O(N)  
📦 Space Complexity: O(1)
*/

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeNthFromEnd(Node* head, int N) {
    Node* dummy = new Node(-1);       // Dummy node to handle edge cases
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    // Step 1: Move fast N steps ahead
    for (int i = 0; i < N; i++) {
        if (fast->next == nullptr) return head; // Edge case: N > length
        fast = fast->next;
    }

    // Step 2: Move both pointers till fast reaches last node
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 3: Remove the N-th node
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;  // Free memory

    return dummy->next;  // Return modified list (excluding dummy)
}
