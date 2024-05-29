#include<iostream>
using namespace std;
class Circle{
    private:
        double radius;
    public:
        Circle(double r){
            radius = r;
        }
        double getArea();
        double getPerimeter();
};
double Circle:: getArea(){
    return 3.14 * radius * radius; 
}
double Circle:: getPerimeter(){
    return 2 * 3.14 * radius;
}   
int main(){
    double rad;
    cout <<"Enter the radius of the circle: ";
    cin >>rad;
    Circle c(rad);
    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;
    return 0;
}