/*
✅ Check if a Linked List is a Palindrome (Two Approaches)
🔗 Problem: Given the head of a singly linked list, return true if it's a palindrome.

---------------------------------------------------
🧠 Approach 1: Using Stack
📈 Time Complexity: O(N)
📦 Space Complexity: O(N)

🧠 Approach 2: Reverse the Second Half of the List (Optimal)
📈 Time Complexity: O(N)
📦 Space Complexity: O(1)

✨ Includes:
- reverseList() helper
- Both isPalindrome versions
*/

#include <stack>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


/// ✅ Helper: Reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while (curr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


/// ✅ Approach 1: Check Palindrome using Stack
bool isPalindromeUsingStack(Node* head) {
    if (!head || !head->next) return true; // empty or single-node list

    stack<int> st;
    Node* temp = head;

    // Push all elements to stack
    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Compare elements from beginning
    temp = head;
    while (temp) {
        if (temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}


/// ✅ Approach 2: Check Palindrome by Reversing Second Half (Optimal)
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* secondHalfHead = reverseList(slow->next);
    Node* firstHalfHead = head;
    Node* temp = secondHalfHead;

    // Step 3: Compare both halves
    while (temp) {
        if (firstHalfHead->data != temp->data) {
            reverseList(secondHalfHead); // Restore list before returning
            return false;
        }
        firstHalfHead = firstHalfHead->next;
        temp = temp->next;
    }

    // Step 4: Restore the original list
    slow->next = reverseList(secondHalfHead);

    return true;
}
