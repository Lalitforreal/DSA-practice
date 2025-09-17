#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    Node* current = head;
    while(current!= nullptr){
        Node* runner = current;
        while(runner->next !=nullptr){
            if(runner->next->val == current->val){
                //delete duplicate
                Node* dup = runner->next;
                runner->next = runner->next->next;
                delete dup;
            }else{
                runner = runner->next;
            }
        }

        current = current ->next;

    }
    return head;
}

void printList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << p->val;
        if (p->next) cout << " -> ";
        p = p->next;
    }
    cout << " -> NULL\n";
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(18);
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next = new Node(3);

    cout << "Input:  "; printList(head);
    head = removeDuplicates(head);
    cout << "Output: "; printList(head);

    return 0;
}

