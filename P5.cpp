#include<iostream>
using namespace std;
class Complex{
    private:
        int real;
        int imag;
    public:
        Complex(int r=0.0, int i=0.0){
            real = r;
            imag = i;
        }
        Complex(const Complex &c){
            real = c.real;
            imag = c.imag;
        }
        Complex add(Complex c){
            Complex temp;
            temp.real = real + c.real;
            temp.imag = imag + c.imag;
            return temp;
        }
        Complex sub(Complex c){
            Complex temp;
            temp.real = real - c.real;
            temp.imag = imag - c.imag;
            return temp;
        }
        Complex mul(Complex c){
            Complex temp;
            temp.real = real*c.real - imag*c.imag;
            temp.imag = real*c.imag + imag*c.real;
            return temp;
        }
        Complex div(Complex c){
            Complex temp;
            temp.real = (real*c.real + imag*c.imag)/(c.real*c.real + c.imag*c.imag);
            temp.imag = (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag);
            return temp;
        }
        void display(){
            cout<<real<<" + "<<imag<<"i"<<endl;
        }
};
int main(){
    Complex c1(3, 4), c2(5, 6), c3;
    c3 = c1.add(c2);
    cout<<"Addition of two complex numbers: ";
    c3.display();
    c3 = c1.sub(c2);
    cout<<"Subtraction of two complex numbers: ";
    c3.display();
    c3 = c1.mul(c2);
    cout<<"Multiplication of two complex numbers: ";
    c3.display();
    c3 = c1.div(c2);
    cout<<"Division of two complex numbers: ";
    c3.display();
    return 0;
}