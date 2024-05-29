#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    private:
        double base, height;
    public:
        Triangle(double b, double h) : base(b), height(h) {}
        double getArea() {
            return 0.5 * base * height;
        }
};

class Rectangle {
    private:
        double length, width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}
        double getArea() {
            return length * width;
        }
};

class Square {
    private:
        double side;
    public:
        Square(double s) : side(s) {}
        double getArea() {
            return side * side;
        }
};

int main() {
    double base, height, length, width, side;

    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;
    Triangle triangle(base, height);
    cout << "Area of Triangle: " << triangle.getArea() << endl;

    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    Rectangle rectangle(length, width);
    cout << "Area of Rectangle: " << rectangle.getArea() << endl;

    cout << "Enter the side of the square: ";
    cin >> side;
    Square square(side);
    cout << "Area of Square: " << square.getArea() << endl;

    return 0;
}
