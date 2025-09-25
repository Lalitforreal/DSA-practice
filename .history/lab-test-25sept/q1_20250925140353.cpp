#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Append a node at the end
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

// Merge two sorted DLLs (recursive)
Node* mergeSorted(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

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

    int n1, n2, val;

    cout << "Enter number of elements in first sorted list: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted elements: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        append(head1, val);
    }

    cout << "Enter number of elements in second sorted list: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted elements: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        append(head2, val);
    }

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    Node* merged = mergeSorted(head1, head2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}