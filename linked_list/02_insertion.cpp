//  1. Insert at Head
// Inserts a new node at the beginning of the list.
// Time: O(1), Space: O(1)
Node* insertAtHead(Node* head, int val) {
    return new Node(val, head); // New node points to old head
}

// 2. Insert at Tail
// Inserts a new node at the end of the list.
// Time: O(N), Space: O(1)
Node* insertAtTail(Node* head, int val) {
    if (head == nullptr) return new Node(val); // If empty list

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node(val); // Add node at end
    return head;
}

//  3. Insert at K-th Position (1-based index)
// Inserts node at position K (1-based).
// Time: O(K), Space: O(1)
Node* insertAtK(Node* head, int val, int K) {
    if (K == 1) return new Node(val, head); // Insert at head

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < K - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) return head; // Invalid K

    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;

    return head;
}

// 4. Insert Before a Given Value (first occurrence)
// Inserts a new node before the first occurrence of value X.
// Time: O(N), Space: O(1)
Node* insertBeforeValue(Node* head, int val, int X) {
    if (head == nullptr) return nullptr; // Empty list

    if (head->data == X) {
        return new Node(val, head); // Insert at head
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != X) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return head; // Value X not found

    Node* newNode = new Node(val, temp);
    prev->next = newNode;

    return head;
}
