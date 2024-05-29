#include <iostream>
using namespace std;

class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

        Complex add(const Complex& c) {
            return Complex(real + c.real, imaginary + c.imaginary);
        }

        void display() {
            cout << real << " + " << imaginary << "i" << endl;
        }
};

int main() {
    double real1, imaginary1, real2, imaginary2;

    cout << "Enter the real and imaginary parts of the first complex number: ";
    cin >> real1 >> imaginary1;
    Complex c1(real1, imaginary1);

    cout << "Enter the real and imaginary parts of the second complex number: ";
    cin >> real2 >> imaginary2;
    Complex c2(real2, imaginary2);

    Complex result = c1.add(c2);

    cout << "The sum of the two complex numbers is: ";
    result.display();

    return 0;
}
