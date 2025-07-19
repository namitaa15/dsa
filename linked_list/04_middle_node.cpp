// Find Middle (Brute Force - Two Pass)
// Step 1: Count nodes
// Step 2: Move to the middle node
// Time: O(N), Space: O(1)
Node* findMiddleBruteForce(Node* head) {
    if (head == nullptr) return nullptr; // Empty list

    // Count total number of nodes
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Find middle index (0-based)
    int midIndex = count / 2;

    // Move to the middle node
    temp = head;
    while (midIndex--) {
        temp = temp->next;
    }

    return temp; // Middle node
}

// Find Middle (Optimal - Tortoise & Hare)
// Fast moves 2 steps, slow moves 1 step
// When fast reaches end, slow is at middle
// Time: O(N), Space: O(1)
Node* findMiddleOptimal(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move slow by 1
        fast = fast->next->next;   // Move fast by 2
    }

    return slow; // Middle node
}
