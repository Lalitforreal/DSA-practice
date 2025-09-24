#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Insert functions
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
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
        cout << "Position out of bounds! Inserting at end instead.\n";
        return insertAtEnd(head, data);
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

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

int main() {
    Node* head = nullptr;
    int n, data, choice, pos;

    // Input initial DLL
    cout << "Enter number of elements in the DLL: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insertAtEnd(head, data);
    }

    cout << "Initial DLL: ";
    printList(head);

    // Menu operations
    while (true) {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n";
        cout << "4. Delete at beginning\n5. Delete at end\n6. Delete at position\n";
        cout << "7. Display\n8. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> data;
                head = insertAtBeginning(head, data);
                cout << "DLL: "; printList(head);
                break;
            case 2:
                cout << "Enter value: "; cin >> data;
                head = insertAtEnd(head, data);
                cout << "DLL: "; printList(head);
                break;
            case 3:
                cout << "Enter value: "; cin >> data;
                cout << "Enter position: "; cin >> pos;
                head = insertAtPosition(head, data, pos);
                cout << "DLL: "; printList(head);
                break;
            case 4:
                head = deleteAtBeginning(head);
                cout << "DLL: "; printList(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                cout << "DLL: "; printList(head);
                break;
            case 6:
                cout << "Enter position: "; cin >> pos;
                head = deleteAtPosition(head, pos);
                cout << "DLL: "; printList(head);
                break;
            case 7:
                cout << "DLL: "; printList(head);
                break;
            case 8:
                freeList(head);
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
}