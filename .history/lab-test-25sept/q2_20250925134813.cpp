#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++; // every time we compare
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++; // count swaps
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int comparisons, swaps;
    bubbleSort(arr, n, comparisons, swaps);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    cout << "Total Comparisons: " << comparisons << "\n";
    cout << "Total Swaps: " << swaps << "\n";

    return 0;
}