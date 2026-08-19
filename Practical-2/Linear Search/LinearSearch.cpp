#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n, key;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
        cout << "Position: " << result + 1 << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}