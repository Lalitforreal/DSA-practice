#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Delete functions
Node* deleteAtBeginning(Node* head) {
    if (!head) {
        cout << "List is empty!\n";
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (!head) {
        cout << "List is empty!\n";
        return nullptr;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = nullptr;
    else head = nullptr; // only one node
    delete temp;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (!head) {
        cout << "List is empty!\n";
        return nullptr;
    }
    if (pos == 0) return deleteAtBeginning(head);

    Node* temp = head;
    for (int i = 0; i < pos && temp; i++) temp = temp->next;

    if (!temp) {
        cout << "Position out of bounds!\n";
        return head;
    }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    return head;
}

// Print DLL
void printList(Node* head) {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

// Free memory
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Build DLL from user input
Node* buildList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    Node* head = nullptr;
    int n, choice, pos;

    cout << "Enter number of elements in the DLL: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    head = buildList(n);

    cout << "Initial DLL: ";
    printList(head);

    while (true) {
        cout << "\n1. Delete at beginning\n2. Delete at end\n3. Delete at position\n4. Display\n5. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1:
                head = deleteAtBeginning(head);
                cout << "DLL: "; printList(head);
                break;
            case 2:
                head = deleteAtEnd(head);
                cout << "DLL: "; printList(head);
                break;
            case 3:
                cout << "Enter position: "; cin >> pos;
                head = deleteAtPosition(head, pos);
                cout << "DLL: "; printList(head);
                break;
            case 4:
                cout << "DLL: "; printList(head);
                break;
            case 5:
                freeList(head);
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
}