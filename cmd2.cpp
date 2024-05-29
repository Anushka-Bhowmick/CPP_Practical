#include <iostream>
#include <cmath>

using namespace std;

class Cone {
private:
    double radius;
    double height;

public:
    Cone(double r, double h) {
        radius = r;
        height = h;
    }

    double getArea() {
        double baseArea = M_PI * radius * radius;
        double slantHeight = sqrt(radius * radius + height * height);
        double surfaceArea = M_PI * radius * (radius + slantHeight);
        return baseArea + surfaceArea;
    }

    double getVolume() {
        return (1.0 / 3.0) * M_PI * radius * radius * height;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <radius> <height>" << endl;
        return 1;
    }

    double radius = atof(argv[1]);
    double height = atof(argv[2]);

    Cone cone(radius, height);

    cout << "Area of the cone: " << cone.getArea() << endl;
    cout << "Volume of the cone: " << cone.getVolume() << endl;

    return 0;
}