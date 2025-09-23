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

Node* insertSorted(Node* head, int data) {
    Node* newNode = new Node(data);
    //if empty list or insert at beggining
    if (!head || data < head->data) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return head;
    }
    //transverse to find posn
    Node* temp = head;
    while (temp->next && temp->next->data < data)
        temp = temp->next;

    //insert after temp
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
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
    Node* head = nullptr;
    int n, data, choice;

    // Input initial elements
    cout << "Enter number of initial elements in sorted DLL: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insertSorted(head, data); // maintain sorted order
    }

    cout << "Initial sorted DLL: ";
    printList(head);

    // Menu for further insertions
    while (true) {
        cout << "\n1. Insert element\n2. Display DLL\n3. Exit\n";
        cout << "Enter choice: "; 
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                head = insertSorted(head, data);
                cout << "Sorted DLL: ";
                printList(head);
                break;
            case 2:
                cout << "Sorted DLL: ";
                printList(head);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}