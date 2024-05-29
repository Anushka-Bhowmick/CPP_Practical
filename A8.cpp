#include <iostream>
using namespace std;

class DB;  

class DM {
private:
    int meter;
    int centimeter;

public:
    DM(int m = 0, int cm = 0) : meter(m), centimeter(cm) {}

    friend void add(DM, DB);
    void display() const {
        cout << "Distance: " << meter << " meters and " << centimeter << " centimeters" << endl;
    }
};

class DB {
private:
    int feet;
    int inches;

public:
    DB(int f = 0, int in = 0) : feet(f), inches(in) {}

    friend void add(DM, DB);
    void display() const {
        cout << "Distance: " << feet << " feet and " << inches << " inches" << endl;
    }
};

void add(DM d1, DB d2) {
    int meter = d2.feet * 0.3048 + d2.inches * 0.0254;
    int cm = d1.centimeter;

    meter += d1.meter;
    cm += d1.centimeter;

    if (cm >= 100) {
        meter += cm / 100;
        cm %= 100;
    }

    cout << "Resultant Distance: " << meter << " meters and " << cm << " centimeters" << endl;
}

int main() {
    int meter, centimeter;
    cout << "Enter distance in meters: ";
    cin >> meter;
    cout << "Enter distance in centimeters: ";
    cin >> centimeter;
    DM dm(meter, centimeter);

    int feet, inches;
    cout << "Enter distance in feet: ";
    cin >> feet;
    cout << "Enter distance in inches: ";
    cin >> inches;
    DB db(feet, inches);

    add(dm, db);

    return 0;
}
