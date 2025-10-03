#include <iostream>
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

void insertTerm(Node*& head, int coeff, int pow) {
    if (coeff == 0) return;

    // If list is empty
    if (!head) {
        head = createNode(coeff, pow);
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Find position to insert (sorted by power)
    while (temp && temp->pow > pow) {
        prev = temp;
        temp = temp->next;
    }

    // If same power exists, just add coefficient
    if (temp && temp->pow == pow) {
        temp->coeff += coeff;
        if (temp->coeff == 0) { // remove if coeff becomes 0
            if (prev) prev->next = temp->next;
            else head = temp->next;
            delete temp;
        }
        return;
    }

    // Otherwise insert new node
    Node* newNode = createNode(coeff, pow);
    if (!prev) { // insert at head
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = temp;
        prev->next = newNode;
    }
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    for (Node* p1 = poly1; p1 != nullptr; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != nullptr; p2 = p2->next) {
            int newCoeff = p1->coeff * p2->coeff;
            int newPow = p1->pow + p2->pow;
            insertTerm(result, newCoeff, newPow);
        }
    }

    return result;
}

void displayPolynomial(Node* head) {
    if (!head) {
        cout << "0" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper: create polynomial from arrays
Node* createPolynomial(int coeffs[], int pows[], int n) {
    Node* poly = nullptr;
    for (int i = 0; i < n; i++) {
        insertTerm(poly, coeffs[i], pows[i]);
    }
    return poly;
}

int main() {
    // First polynomial: 3x^2 + 2x^1 + 1
    int coeffs1[] = {3, 2, 1};
    int pows1[] = {2, 1, 0};
    Node* poly1 = createPolynomial(coeffs1, pows1, 3);

    // Second polynomial: 2x^1 + 4
    int coeffs2[] = {2, 4};
    int pows2[] = {1, 0};
    Node* poly2 = createPolynomial(coeffs2, pows2, 2);

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    Node* result = multiplyPolynomials(poly1, poly2);

    cout << "Result after multiplication: ";
    displayPolynomial(result);

    return 0;
}