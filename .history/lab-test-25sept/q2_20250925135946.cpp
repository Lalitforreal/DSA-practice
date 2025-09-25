// Q. Given a pair linked lists, insert nodes of second linked list into the first linked list at alternate positions. Assume that the first linked list has at least as many elements as the second.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// push node at front
void push(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void mergeAlternate(Node* &first, Node* &second) {
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

    // Update second list to empty
    second = curr2; 
}

int main() {
    Node* first = nullptr;
    Node* second = nullptr;

    // First list: 1->2->3
    for (int i = 3; i >= 1; i--) push(first, i);

    // Second list: 4->5
    push(second, 4);
    push(second, 5);


    cout << "First List: ";
    printList(first);

    cout << "Second List: ";
    printList(second);

    mergeAlternate(first, second);

    cout << "After Merge, First List: ";
    printList(first);

    cout << "After Merge, Second List: ";
    printList(second); // should be empty

    return 0;
}