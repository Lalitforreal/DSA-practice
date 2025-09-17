#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {

    }
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse current link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev; // new head
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head -> next ->next->next->next = new Node(5);

    cout<<"Original List : ";
    printList(head);

    head = reverseList(head);

    cout<<"Reversed List : ";
    printList(head);
    return 0;
}