#include <iostream>
#include <cmath>   
using namespace std;

struct Node {
    int coeff;   
    int pow;     
    Node* next;
};


Node* createNode(int coeff, int pow) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = nullptr;
    return newNode;
}

//at end
void insertTerm(Node*& head, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int evaluatePolynomial(Node* head, int x) {
    int result = 0;
    Node* temp = head;
    while (temp) {
        result += temp->coeff * pow(x, temp->pow);
        temp = temp->next;
    }
    return result;
}


//delete power wala section
void deletePower(Node*& head, int power) {
    // if head nodes have the power
    while (head && head->pow == power) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    // Traverse baaki ka list
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->pow == power) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

void displayPolynomial(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* poly = nullptr;

    insertTerm(poly, 5, 3);
    insertTerm(poly, 4, 2);
    insertTerm(poly, 2, 1);
    insertTerm(poly, 1, 0);

    cout << "Polynomial: ";
    displayPolynomial(poly);

    int x;
    cout << "value of x: ";
    cin >> x;

    int result = evaluatePolynomial(poly, x);
    cout << "Result = " << result << endl;

    return 0;
}