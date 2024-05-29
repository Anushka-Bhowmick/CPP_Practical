#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
    }

    void display() const {
        cout << real << " + " << imag << "i";
    }
};

int main() {
    Complex a(1, 2), b(3, 4), c(5, 6), d(7, 8);
    Complex result = a - b * c + d;

    cout << "Result of expression a - b * c + d: ";
    result.display();
    cout << endl;

    return 0;
}
