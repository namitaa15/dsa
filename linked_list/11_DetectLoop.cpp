/*
✅ Detect a Loop in a Linked List (3 Approaches)

📌 Problem:
Given the head of a singly linked list, detect whether there is a cycle (loop) in the list.
If yes, return true; else, return false.

---------------------------------------------------------------------
🔹 Approach 1: Hashing using unordered_map
🧠 Idea: Store visited nodes in a hash map. If a node repeats → loop exists.
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

bool detectLoopHashing(Node* head) {
    unordered_map<Node*, bool> visited;
    Node* temp = head;

    while (temp) {
        if (visited[temp]) return true;  // Loop detected
        visited[temp] = true;
        temp = temp->next;
    }

    return false;  // No loop
}


/*
---------------------------------------------------------------------
🔹 Approach 2: Floyd's Cycle Detection Algorithm (Tortoise & Hare)
🧠 Idea: Use two pointers — slow moves 1 step, fast moves 2 steps.
If they meet → loop exists.
📈 Time Complexity: O(N)
📦 Space Complexity: O(1)
*/

bool detectLoopFloyd(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;  // Loop detected
    }

    return false;  // No loop
}


/*
---------------------------------------------------------------------
🔹 Approach 3: Find Length of Loop (if exists) using Floyd’s Algorithm
🧠 Idea: First detect loop using slow/fast pointers, then count length of the cycle.
📈 Time Complexity: O(N)
📦 Space Complexity: O(1)
*/

int findLoopLengthFloyd(Node* head) {
    if (!head || !head->next) return 0;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Count loop length
            int count = 1;
            Node* temp = slow->next;
            while (temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    return 0;  // No loop
}
