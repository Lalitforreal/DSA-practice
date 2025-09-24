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

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertAtPosition(Node* head, int data, int pos) {
    if (pos == 0) return insertAtBeginning(head, data);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) {
        cout << "Position out of bounds!\n";
        return head;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data, pos;

    while (true) {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Display\n5. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> data;
                head = insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter value: "; cin >> data;
                head = insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter value: "; cin >> data;
                cout << "Enter position: "; cin >> pos;
                head = insertAtPosition(head, data, pos);
                break;
            case 4:
                cout << "DLL: "; printList(head);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
}