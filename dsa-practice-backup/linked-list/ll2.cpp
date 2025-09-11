//find mid using count

#include <iostream>
using namespace std;

struct Node { //used to represent a node in ll
    int data; //stores teh value of the node
    Node* next; //a pointer to another node
    Node(int val) { //constructer (runs when you create a new node)
        data = val;
        next = nullptr; //makes sure the new node doesn't p oint anywhere
    }
};

Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;

    // Step 1: Count nodes
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Step 2: Find middle index
    int midIndex = count / 2;

    // Step 3: Traverse to midIndex
    temp = head;
    for (int i = 0; i < midIndex; i++) {
        temp = temp->next;
    }

    return temp; // middle node
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* mid = findMiddle(head);

    if (mid != nullptr) {
        cout << "Middle element is: " << mid->data << endl;
    }

    return 0;
}