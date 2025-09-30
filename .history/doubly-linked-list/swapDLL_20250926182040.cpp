#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

// Swap nodes
Node* swapFirstTwoNodes(Node* head) {
    if (!head || !head->next) return head;
    Node* first = head;
    Node* second = head->next;
    // Step 1: Update first node's next
    first->next = second->next;
    if (second->next) second->next->prev = first;
    
    // Step 2: Update second node's pointers
    second->prev = nullptr;
    second->next = first;
    first->prev = second;
    return second; // new head
}

// Swap data only
void swapFirstTwoData(Node* head) {
    if (!head || !head->next) return;
    int temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Original DLL: ";
    printList(head);

    // Swap nodes
    head = swapFirstTwoNodes(head);
    cout << "After swapping first two nodes: ";
    printList(head);

    // Swap data
    swapFirstTwoData(head);
    cout << "After swapping first two data: ";
    printList(head);

    return 0;
}