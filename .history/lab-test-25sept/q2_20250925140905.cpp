#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Append node at end (to keep natural order)
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode; //last me add
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Merge second list into first at alternate positions
void mergeAlternate(Node*& first, Node*& second) {
    Node* curr1 = first;
    Node* curr2 = second;
    Node* next1, *next2;

    while (curr1 && curr2) {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }

    // Remaining nodes in second list
    second = curr2;
}

int main() {
    Node* first = nullptr;
    Node* second = nullptr;

    int n1, n2, val;
    cout << "Enter number of elements in first list: ";
    cin >> n1;
    cout << "Enter " << n1 << " elements: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        append(first, val);
    }

    cout << "Enter number of elements in second list: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        append(second, val);
    }

    cout << "First List: ";
    printList(first);

    cout << "Second List: ";
    printList(second);

    mergeAlternate(first, second);

    cout << "Final List: ";
    printList(first);

    cout << "Second list: ";
    printList(second); // empty milegi

    return 0;
}
