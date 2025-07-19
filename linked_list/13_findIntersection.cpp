/*
✅ Find the Intersection Node of Two Singly Linked Lists

🧠 Goal: Return the first node where two singly linked lists intersect.

-----------------------------------------------------
🔹 Approach 1: Brute Force (Two Nested Loops)
📈 Time: O(M * N)
📦 Space: O(1)
*/

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findIntersectionBrute(Node* head1, Node* head2) {
    while (head1) {
        Node* temp = head2;
        while (temp) {
            if (head1 == temp) return head1;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return nullptr;
}


/*
-----------------------------------------------------
🔹 Approach 2: Using Hashing (Unordered Set)
📈 Time: O(M + N)
📦 Space: O(M)
*/

#include <unordered_set>
using namespace std;

Node* findIntersectionHashing(Node* head1, Node* head2) {
    unordered_set<Node*> nodes;
    while (head1) {
        nodes.insert(head1);
        head1 = head1->next;
    }
    while (head2) {
        if (nodes.find(head2) != nodes.end()) return head2;
        head2 = head2->next;
    }
    return nullptr;
}


/*
-----------------------------------------------------
🔹 Approach 3: Length Difference Method
📈 Time: O(M + N)
📦 Space: O(1)
*/

int getLength(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

Node* findIntersectionLength(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Move longer list ahead
    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    // Move together and check
    while (head1 && head2) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}


/*
-----------------------------------------------------
🔹 Approach 4: Two Pointer Technique (Optimal)
📈 Time: O(M + N)
📦 Space: O(1)

💡 Trick: Both pointers will traverse same total length (M + N).
*/

Node* findIntersectionTwoPointer(Node* head1, Node* head2) {
    if (!head1 || !head2) return nullptr;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }

    return ptr1;  // May be null (no intersection) or intersection node
}
