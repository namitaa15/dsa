/*
✅ Reverse Linked List in Groups of K Nodes

🔗 Problem:
Given the head of a linked list and an integer `k`, reverse the list in groups of size `k`.

🧠 Idea:
- Use a dummy node for ease.
- Find the kth node.
- Break the list, reverse the chunk, reconnect, repeat.

📈 Time Complexity: O(N) — each node is visited once  
📦 Space Complexity: O(1) — constant space (in-place reversal)
*/

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 🔹 Helper 1: Find the K-th node from the current position
Node* getKthNode(Node* start, int k) {
    while (start && --k) {
        start = start->next;
    }
    return start;
}

// 🔹 Helper 2: Reverse a portion of the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// 🔹 Main Function: Reverse the list in K-groups
Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prevGroupEnd = dummy;

    while (true) {
        // Step 1: Find the K-th node
        Node* kthNode = getKthNode(prevGroupEnd->next, k);
        if (!kthNode) break; // If less than k nodes, stop

        // Step 2: Break the list after K nodes
        Node* nextGroupStart = kthNode->next;
        kthNode->next = nullptr;

        // Step 3: Reverse current group
        Node* groupStart = prevGroupEnd->next;
        Node* reversedHead = reverseList(groupStart);

        // Step 4: Connect reversed group with the previous and next parts
        prevGroupEnd->next = reversedHead;
        groupStart->next = nextGroupStart;

        // Step 5: Move prevGroupEnd for next iteration
        prevGroupEnd = groupStart;
    }

    return dummy->next;
}
