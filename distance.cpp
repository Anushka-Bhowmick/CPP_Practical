#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches %= 12;
        } else if (inches < 0) {
            feet -= (-inches) / 12 + 1;
            inches = 12 - (-inches) % 12;
        }
    }

public:
    Distance() : feet(0), inches(0) {}

    Distance(int f, int i) : feet(f), inches(i) {
        normalize();
    }

    Distance operator+(const Distance& d) const {
        return Distance(feet + d.feet, inches + d.inches);
    }

    Distance operator-(const Distance& d) const {
        return Distance(feet - d.feet, inches - d.inches);
    }

    bool operator==(const Distance& d) const {
        return (feet == d.feet) && (inches == d.inches);
    }

    bool operator>(const Distance& d) const {
        if (feet > d.feet) return true;
        if (feet == d.feet && inches > d.inches) return true;
        return false;
    }

    bool operator<(const Distance& d) const {
        if (feet < d.feet) return true;
        if (feet == d.feet && inches < d.inches) return true;
        return false;
    }

    friend ostream& operator<<(ostream& out, const Distance& d) {
        out << d.feet << " feet " << d.inches << " inches";
        return out;
    }

    friend istream& operator>>(istream& in, Distance& d) {
        cout << "Enter feet: ";
        in >> d.feet;
        cout << "Enter inches: ";
        in >> d.inches;
        d.normalize();
        return in;
    }
};

int main() {
    Distance d1, d2;
    cout << "Enter first distance:" << endl;
    cin >> d1;
    cout << "Enter second distance:" << endl;
    cin >> d2;

    cout << "\nFirst Distance: " << d1 << endl;
    cout << "Second Distance: " << d2 << endl;

    Distance d3 = d1 + d2;
    cout << "\nAfter adding: " << d3 << endl;

    Distance d4 = d1 - d2;
    cout << "After subtracting: " << d4 << endl;

    if (d1 == d2) {
        cout << "Distances are equal." << endl;
    } else if (d1 > d2) {
        cout << "First distance is greater than second distance." << endl;
    } else {
        cout << "First distance is less than second distance." << endl;
    }

    return 0;
}
