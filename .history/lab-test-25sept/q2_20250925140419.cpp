#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Utility: append at end
void append(Node*& head, int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Insert nodes of second list into first at alternate positions
void mergeAlternate(Node*& first, Node*& second) {
    Node* curr1 = first;
    Node* curr2 = second;
    Node* next1, *next2;

    while (curr1 && curr2) {
        // Save next pointers
        next1 = curr1->next;
        next2 = curr2->next;

        // Insert curr2 after curr1
        curr1->next = curr2;
        curr2->next = next1;

        // Move ahead
        curr1 = next1;
        curr2 = next2;
    }

    // Remaining nodes in second list stay as-is (if any)
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

    cout << "After Merge, First List: ";
    printList(first);

    cout << "After Merge, Second List: ";
    printList(second); // should be empty if lengths allow full merge

    return 0;
}