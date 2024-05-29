#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);

    void display() const {
        cout << real << " + " << imag << "i";
    }
};

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
}

int main() {
    Complex a(1, 2), b(3, 4), c(5, 6), d(7, 8);
    Complex result = a - b * c + d;

    cout << "Result of expression a - b * c + d: ";
    result.display();
    cout << endl;

    return 0;
}
