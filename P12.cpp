#include <iostream>

using namespace std;

class DerivedComplexNumber;

class ComplexNumber {
protected:
    float real;
    float imaginary;

public:
    ComplexNumber() {
        cout << "Enter the real part of the complex number: ";
        cin >> real;
        cout << "Enter the imaginary part of the complex number: ";
        cin >> imaginary;
    }

    void display() {
        cout << "Complex Number: " << real << " + " << imaginary << "i" << endl;
    }

    friend class FriendComplexNumber;
};

class DerivedComplexNumber : public ComplexNumber {
private:
    float add_real;
    float add_imaginary;

public:
    DerivedComplexNumber() {
        cout << "Enter the real part of the complex number to add: ";
        cin >> add_real;
        cout << "Enter the imaginary part of the complex number to add: ";
        cin >> add_imaginary;
    }

    void addComplex() {
        real += add_real;
        imaginary += add_imaginary;
        cout << "Result after addition:" << endl;
        display();
    }

    friend class FriendComplexNumber;
};

class FriendComplexNumber {
public:
    static void calculateDifference(ComplexNumber base, DerivedComplexNumber derived) {
        float diff_real = base.real - derived.real;
        float diff_imaginary = base.imaginary - derived.imaginary;
        cout << "Difference between base and derived complex numbers: " << diff_real << " + " << diff_imaginary << "i" << endl;
    }
};

int main() {
    ComplexNumber baseComplex;
    baseComplex.display();

    DerivedComplexNumber derivedComplex;
    derivedComplex.addComplex();

    FriendComplexNumber::calculateDifference(baseComplex, derivedComplex);

    return 0;
}
