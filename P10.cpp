#include <iostream>
#include <complex>  
using namespace std;

class ADD {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b, int c) {
        return a + b + c;
    }

    complex<double> add(complex<double> a, complex<double> b) {
        return a + b;
    }
};

int main() {
    ADD addObj;
    
    int sum1 = addObj.add(5, 3);
    cout << "Sum of two integers: " << sum1 << endl;

    float sum2 = addObj.add(3.5, 2.3, 4);
    cout << "Sum of two floats and one integer: " << sum2 << endl;

    complex<double> num1(2.5, 3.5), num2(1.5, 2.5);
    complex<double> sum3 = addObj.add(num1, num2);
    cout << "Sum of two complex numbers: " << sum3.real() << " + " << sum3.imag() << "i" << endl;

    return 0;
}
