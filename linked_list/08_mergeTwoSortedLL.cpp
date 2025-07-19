/*
✅ Merge Two Sorted Linked Lists (Iterative - Two Pointer Approach)

🧠 Problem:
Given two sorted linked lists, merge them into one sorted list and return the head.

🔗 Similar to: Leetcode 21 - Merge Two Sorted Lists

📈 Time Complexity: O(M + N)  
📦 Space Complexity: O(1) (in-place merge)

✨ Logic:
- Use a dummy node to build the new list.
- Use two pointers to compare nodes and attach the smaller one.
- After one list is exhausted, append the remaining nodes of the other list.
*/

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeSortedLists(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);  // Dummy node to simplify head handling
    Node* temp = dummy;

    // Step 1: Traverse both lists and pick smaller nodes
    while (l1 && l2) {
        if (l1->data < l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    // Step 2: Attach remaining nodes (only one of these runs)
    if (l1) temp->next = l1;
    if (l2) temp->next = l2;

    return dummy->next;  // Return merged list head
}
