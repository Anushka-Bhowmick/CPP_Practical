#include <iostream>
using namespace std;

class Height {
private:
    int feet;
    int inches;

public:
    Height(int ft = 0, int in = 0) : feet(ft), inches(in) {}

    double into_cm() const {
        return feet * 30.48 + inches * 2.54;
    }

    Height operator-(const Height& other) const {
        int totalInches1 = feet * 12 + inches;
        int totalInches2 = other.feet * 12 + other.inches;
        int diff = totalInches1 - totalInches2;
        int ft = diff / 12;
        int in = diff % 12;
        return Height(ft, in);
    }

    bool operator<(const Height& other) const {
        int totalInches1 = feet * 12 + inches;
        int totalInches2 = other.feet * 12 + other.inches;
        return totalInches1 < totalInches2;
    }

    bool operator==(const Height& other) const {
        return feet == other.feet && inches == other.inches;
    }
};

int main() {
    Height h1(5, 9), h2(6, 2);
    Height diff = h1 - h2;
    cout << "Difference of heights: " << diff.into_cm() << " cm" << endl;

    if (h1 < h2)
        cout << "Height 1 is less than Height 2" << endl;
    else if (h1 == h2)
        cout << "Height 1 is equal to Height 2" << endl;
    else
        cout << "Height 1 is greater than Height 2" << endl;

    return 0;
}
