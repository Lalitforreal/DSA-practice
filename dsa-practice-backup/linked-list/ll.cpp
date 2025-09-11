//Find mid in a linked list (using fast and slow pointers)


#include <iostream>
using namespace std;

struct Node { //used to represent a node in ll
    int data; //stores teh value of the node
    Node* next; //a pointer to another node
    Node(int val) { //constructer (runs when you create a new node)
        data = val;
        next = nullptr; //makes sure the new node doesn't p oint anywhere
    }
};

Node* findMiddle(Node* head){
    if(head==nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast!=nullptr && fast->next!= nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* mid = findMiddle(head);

    if (mid != nullptr) {
        cout << "Middle element is: " << mid->data << endl;
    }

    return 0;
}