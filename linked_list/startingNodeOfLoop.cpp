/*
✅ Find Starting Node of Loop in Linked List

🧠 Problem:
Given the head of a singly linked list, return the node where the cycle begins.
If no cycle, return NULL.

-------------------------------------------------------------
🔹 Approach 1: Hashing (Using unordered_map)
📈 Time Complexity: O(N)
📦 Space Complexity: O(N)
*/

#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findLoopStartHashing(Node* head) {
    unordered_map<Node*, bool> visited;
    Node* temp = head;

    while (temp) {
        if (visited[temp]) return temp;  // First node already visited → loop start
        visited[temp] = true;
        temp = temp->next;
    }

    return nullptr;  // No loop found
}


/*
-------------------------------------------------------------
🔹 Approach 2: Floyd’s Cycle Detection + Finding Loop Start
📈 Time Complexity: O(N)
📦 Space Complexity: O(1)

💡 Logic:
- Detect cycle using slow & fast pointers.
- Reset slow to head.
- Move both one step at a time.
- Point of meeting is the start of the loop.
*/

Node* findLoopStartFloyd(Node* head) {
    if (!head || !head->next) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect Loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find Loop Start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;  // No loop found
}
