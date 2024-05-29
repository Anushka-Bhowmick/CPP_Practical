#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int intArr[size];
    cout << "Enter the elements of the integer array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> intArr[i];
    }

    cout << "Integer Array before sorting: " << endl;
    printArray(intArr, size);

    bubbleSort(intArr, size);

    cout << "Integer Array after sorting: " << endl;
    printArray(intArr, size);

    cout << endl;

    double doubleArr[size];
    cout << "Enter the elements of the double array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> doubleArr[i];
    }

    cout << "Double Array before sorting: " << endl;
    printArray(doubleArr, size);

    bubbleSort(doubleArr, size);

    cout << "Double Array after sorting: " << endl;
    printArray(doubleArr, size);

    return 0;
}