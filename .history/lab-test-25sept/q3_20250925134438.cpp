#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Utility: append a node at the end
void append(Node*& head, int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

// Print list forward
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Merge two sorted DLLs
Node* mergeSorted(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    // Choose head of merged list
    if (first->data <= second->data) {
        first->next = mergeSorted(first->next, second);
        if (first->next) first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = mergeSorted(first, second->next);
        if (second->next) second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // First sorted DLL: 1 <-> 3 <-> 5
    append(head1, 1);
    append(head1, 3);
    append(head1, 5);
    append(head1, 7);
    append(head1, 9);

    // Second sorted DLL: 2 <-> 4 <-> 6
    append(head2, 2);
    append(head2, 4);
    append(head2, 6);
    append(head2, 8);
    append(head2, 10);

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    Node* merged = mergeSorted(head1, head2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}