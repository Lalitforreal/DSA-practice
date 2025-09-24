#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* deleteAtBeginning(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = nullptr;
    else head = nullptr;
    delete temp;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (!head) return nullptr;
    Node* temp = head;
    if (pos == 0) return deleteAtBeginning(head);
    for (int i = 0; i < pos && temp != nullptr; i++) temp = temp->next;
    if (!temp) {
        cout << "Position out of bounds\n";
        return head;
    }
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    delete temp;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Original DLL: ";
    printList(head);

    head = deleteAtBeginning(head);
    cout << "After deleting beginning: ";
    printList(head);

    head = deleteAtEnd(head);
    cout << "After deleting end: ";
    printList(head);

    head = deleteAtPosition(head, 0);
    cout << "After deleting position 0: ";
    printList(head);

    return 0;
}