#include <iostream>
#include <cmath>

using namespace std;

class Cylinder {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) {
        radius = r;
        height = h;
    }

    double getArea() {
        double baseArea = M_PI * radius * radius;
        double surfaceArea = 2 * M_PI * radius * (radius + height);
        return baseArea + surfaceArea;
    }

    double getCircumference() {
        return 2 * M_PI * radius;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <radius> <height>" << endl;
        return 1;
    }

    double radius = atof(argv[1]);
    double height = atof(argv[2]);

    Cylinder cylinder(radius, height);

    cout << "Area of the cylinder: " << cylinder.getArea() << endl;
    cout << "Circumference of the cylinder: " << cylinder.getCircumference() << endl;

    return 0;
}