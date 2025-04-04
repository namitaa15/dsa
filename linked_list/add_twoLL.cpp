/*
✅ Add Two Numbers Represented by Linked Lists
🔗 Problem: Each node contains a digit; digits are stored in reverse order.
Add the two numbers and return the sum as a linked list.

📥 Input:
L1: 2 → 4 → 3   (Represents 342)
L2: 5 → 6 → 4   (Represents 465)

📤 Output:
7 → 0 → 8       (Represents 807)

🧠 Approach:
- Use a dummy node to simplify result creation.
- Traverse both lists and sum corresponding digits + carry.
- Create a new node with (sum % 10).
- Update carry = sum / 10 after each addition.

📈 Time Complexity: O(max(M, N))  
📦 Space Complexity: O(max(M, N)) where M and N are lengths of L1 and L2.
*/

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);      // Dummy node for result
    Node* current = dummy;           // Pointer to build result list
    int carry = 0;

    // Traverse while either list has elements or carry remains
    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;  // Exclude dummy node
}
