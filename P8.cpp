#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;

public:
    // Constructor
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Copy constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Overload assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Overload + operator for concatenation
    String operator+(const String& other) const {
        String result;
        delete[] result.str;
        result.str = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // Overload comparison operators
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator<(const String& other) const {
        return strcmp(str, other.str) < 0;
    }

    // Display function
    void display() const {
        cout << str;
    }
};

int main() {
    // Prompt the user to enter strings
    cout << "Enter the first string: ";
    char input1[100];
    cin.getline(input1, 100);

    cout << "Enter the second string: ";
    char input2[100];
    cin.getline(input2, 100);

    // Create String objects from user input
    String s1(input1);
    String s2(input2);
    
    // Concatenation
    String s3 = s1 + s2;
    cout << "Concatenated string: ";
    s3.display();
    cout << endl;

    // Assignment
    String s4;
    s4 = s3;
    cout << "Assigned string: ";
    s4.display();
    cout << endl;

    // Comparison
    if (s1 == s2) {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }

    if (s1 < s2) {
        cout << "s1 comes before s2." << endl;
    } else {
        cout << "s1 does not come before s2." << endl;
    }

    return 0;
}
