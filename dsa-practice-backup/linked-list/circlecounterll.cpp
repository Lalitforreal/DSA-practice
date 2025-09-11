
//print multiples of a circular linked list

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to solve Q2 without using set
void printCircularMultiples(Node* head, int k) {
    if (!head) return;

    // Make the list circular
    Node* temp = head;
    int n = 1;  // count total nodes
    while (temp->next) {
        temp = temp->next;
        n++;
    }
    temp->next = head;  // last node points to head

    Node* curr = head;
    int index = 0, printedCount = 0;

    while (printedCount < n) {
        if (index % k == 0) {
            cout << curr->data << " -> ";
            printedCount++;
        }
        curr = curr->next;
        index++;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Input: 12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22
    insertEnd(head, 12);
    insertEnd(head, 15);
    insertEnd(head, 18);
    insertEnd(head, 17);
    insertEnd(head, 19);
    insertEnd(head, 20);
    insertEnd(head, 22);

    int k = 3;
    cout << "Output: ";
    printCircularMultiples(head, k);

    return 0;
}