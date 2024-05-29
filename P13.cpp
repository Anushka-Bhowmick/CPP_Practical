#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void display() = 0;
    virtual double area() = 0;
    virtual ~Shape() { cout << "Shape destroyed" << endl; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r){
        radius = r;
    }
    void display() override {
        cout << "Shape: Circle" << endl;
        cout << "Radius: " << radius << endl;
    }
    double area() override {
        return M_PI * radius * radius;
    }
    ~Circle() { cout << "Circle destroyed" << endl; }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w){
        length = l;
        width = w;
    }
    void display() override {
        cout << "Shape: Rectangle" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }
    double area() override {
        return length * width;
    }
    ~Rectangle() { cout << "Rectangle destroyed" << endl; }
};

class Trapezoid : public Shape {
private:
    double a, b, height;
public:
    Trapezoid(double base1, double base2, double h){
        a = base1;
        b = base2;
        height = h;
    }
    void display() override {
        cout << "Shape: Trapezoid" << endl;
        cout << "Base 1: " << a << endl;
        cout << "Base 2: " << b << endl;
        cout << "Height: " << height << endl;
    }
    double area() override {
        return ((a + b) / 2) * height;
    }
    ~Trapezoid() { cout << "Trapezoid destroyed" << endl; }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Trapezoid(3, 4, 5);

    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];
        cout << endl;
    }
    return 0;
}
