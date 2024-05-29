#include <iostream>
using namespace std;

 Function prototype for call by value
void callByValue(int x);

 Function prototype for call by reference
void callByReference(int &x);
 Function definition for call by value
void callByValue(int x) {
    x = x + 10;
    cout << "Inside callByValue, x = " << x << endl;
}

 Function definition for call by reference
void callByReference(int &x) {
    x = x + 10;
    cout << "Inside callByReference, x = " << x << endl;
}


int main() {
    int number;

     Taking runtime input from the user
    cout << "Enter a number: ";
    cin >> number;

     Demonstrating call by value
    cout << "\nCall by Value:" << endl;
    cout << "Before callByValue, number = " << number << endl;
    callByValue(number);
    cout << "After callByValue, number = " << number << endl;

     Demonstrating call by reference
    cout << "\nCall by Reference:" << endl;
    cout << "Before callByReference, number = " << number << endl;
    callByReference(number);
    cout << "After callByReference, number = " << number << endl;

    return 0;
}

