//print multiples of a singly linked list


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

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print elements at multiples of k indices
void printMultiples(Node* head, int k) {
    int index = 0;
    Node* curr = head;
    while (curr != NULL) {
        if (index % k == 0) {
            cout << curr->data << " -> ";
        }
        curr = curr->next;
        index++;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Creating linked list: 12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22
    insertEnd(head, 12);
    insertEnd(head, 15);
    insertEnd(head, 18);
    insertEnd(head, 17);
    insertEnd(head, 19);
    insertEnd(head, 20);
    insertEnd(head, 22);

    int k = 3;

    cout << "Output: ";
    printMultiples(head, k);

    return 0;
}