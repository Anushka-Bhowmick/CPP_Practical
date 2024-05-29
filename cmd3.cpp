#include <iostream>

using namespace std;

class SameClass {
public:
    void printMessage(SameClass& obj) {
        cout << "Printing message from same class object." << endl;
    }
};

class DifferentClass {
public:
    void printMessage(SameClass& obj) {
        cout << "Printing message from different class object." << endl;
    }
};

int main() {
    SameClass obj1;
    obj1.printMessage(obj1);  (a) pass same class's object

    DifferentClass obj2;
    obj2.printMessage(obj1);  (b) pass different class's object

    return 0;
}