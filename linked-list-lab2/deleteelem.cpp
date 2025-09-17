#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

// Reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Remove nodes that have greater value on right
Node* removeNodes(Node* head) {
    if (!head) return NULL;

    // Step 1: Reverse
    head = reverseList(head);

    // Step 2: Traverse and keep max
    Node* curr = head;
    Node* maxNode = head;
    Node* prev = head;

    curr = curr->next;
    while (curr) {
        if (curr->val < maxNode->val) {
            // delete current node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            maxNode = curr;
            prev = curr;
            curr = curr->next;
        }
    }

    // Step 3: Reverse again
    head = reverseList(head);
    return head;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main() {
    Node* head1 = new Node(10);
    head1->next = new Node(12);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(20);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(16);
    head1->next->next->next->next->next->next = new Node(25);
    head1->next->next->next->next->next->next->next = new Node(8);

    cout << "Input 1:  ";
    printList(head1);
    head1 = removeNodes(head1);
    cout << "Output 1: ";
    printList(head1);



    return 0;
}