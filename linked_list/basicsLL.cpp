#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;       // stores value
    Node* next;     // pointer to next node

    // Constructors
    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

//  Function to create a linked list from an array
// Time: O(N), Space: O(N)
Node* convertArrayToLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = new Node(arr[0]); // create first node
    Node* mover = head;

    for (int i = 1; i < size; i++) {
        Node* temp = new Node(arr[i]); // new node for each value
        mover->next = temp;            // link the node
        mover = temp;                  // move pointer ahead
    }

    return head; // return head of the list
}

//  Function to traverse and print the linked list
// Time: O(N), Space: O(1)
void traverseLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to find the length of linked list
// Time: O(N), Space: O(1)
int lengthOfLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

//  Function to search an element in linked list
// Time: Best O(1), Worst O(N), Avg O(N)
// Space: O(1)
bool searchElement(Node* head, int value) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == value)
            return true; // found
        temp = temp->next;
    }

    return false; // not found
}
