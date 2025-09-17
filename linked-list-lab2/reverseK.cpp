#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

// Reverse in groups of k
Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    // Step 1: check if there are at least k nodes
    Node* temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k) return head; // not enough nodes, no reversal

    // Step 2: reverse k nodes
    count = 0;
    curr = head;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: connect recursively
    if (next) {
        head->next = reverseKGroup(next, k);
    }

    return prev; // new head of this block
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
    // Build list: 1->2->3->4->5->6->7->8->12->7
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next->next->next = new Node(7);

    cout << "Input:  ";
    printList(head);

    head = reverseKGroup(head, 4);

    cout << "Output: ";
    printList(head);

    return 0;
}