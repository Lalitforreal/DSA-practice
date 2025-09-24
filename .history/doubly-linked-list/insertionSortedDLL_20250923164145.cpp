int main() {
    Node* head = nullptr;
    int n, data, choice;

    // Input initial elements
    cout << "Enter number of initial elements in sorted DLL: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insertSorted(head, data); // maintain sorted order
    }

    cout << "Initial sorted DLL: ";
    printList(head);

    // Menu for further insertions
    while (true) {
        cout << "\n1. Insert element\n2. Display DLL\n3. Exit\n";
        cout << "Enter choice: "; 
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                head = insertSorted(head, data);
                cout << "Sorted DLL: ";
                printList(head);
                break;
            case 2:
                cout << "Sorted DLL: ";
                printList(head);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}