// Delete head node
// Time: O(1), Space: O(1)
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp; // free memory
    return head;
}
// Delete tail node
// Time: O(N), Space: O(1)
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next; // free last node
    temp->next = nullptr;
    return head;
}

// Delete K-th node (1-based index)
// Time: O(K), Space: O(1)
Node* deleteKthNode(Node* head, int K) {
    if (head == nullptr) return nullptr;

    if (K == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < K - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) return head; // If K is greater than the length of the list, return head as it is

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
}

// Delete node by value (first occurrence)
// Time: O(N), Space: O(1)
Node* deleteByValue(Node* head, int val) {
    if (head == nullptr) return nullptr;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return head; // value not found

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}
