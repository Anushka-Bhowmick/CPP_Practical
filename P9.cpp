#include<iostream>
using namespace std;
class Complex{
    private:
        double real, imag;
    public:
        Complex(double r=0.0, double i=0.0){
            real = r;
            imag = i;
        }
        Complex (const Complex &c){
            real = c.real;
            imag = c.imag;
        }
        Complex operator+(const Complex &c){
            return Complex(real + c.real, imag + c.imag);
        }
        Complex operator-(const Complex &c){
            return Complex(real - c.real, imag - c.imag);
        }
        Complex operator*(const Complex &c){
            return Complex(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
        }
        Complex operator/(const Complex &c){
            return Complex((real*c.real + imag*c.imag)/(c.real*c.real + c.imag*c.imag), (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag));
        }
        void display(){
            cout<<real<<" + "<<imag<<"i"<<endl;
        }

};
int main()
{
    double r1, i1, r2, i2, r3, i3, r4, i4;
    cout<<"Enter the real and imaginary part of the first complex number: "<<endl;
    cin>>r1>>i1;
    cout<<"Enter the real and imaginary part of the second complex number: "<<endl;
    cin>>r2>>i2;
    cout<<"Enter the real and imaginary part of the third complex number: "<<endl;
    cin>>r3>>i3;
    cout<<"Enter the real and imaginary part of the fourth complex number: "<<endl;
    cin>>r4>>i4;
    Complex c1(r1, i1), c2(r2, i2), c3(r3, i3), c4(r4, i4),c5;
    c5 = c1 - c2 * c3 + c4;
    
    c5.display();
    return 0;
}