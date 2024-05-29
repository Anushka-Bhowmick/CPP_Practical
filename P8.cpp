#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    String operator+(const String& other) const {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        return String(temp);
    }

    bool operator<(const String& other) const {
        return strcmp(str, other.str) < 0;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    void display() const {
        cout << str;
    }
};

int main() {
    String s1("Hello");
    String s2("World");

    String s3 = s1 + s2;
    cout << "Concatenated string: ";
    s3.display();
    cout << endl;

    String s4 = s1;
    cout << "Assigned string: ";
    s4.display();
    cout << endl;

    if (s1 < s2)
        cout << "String 1 is less than String 2" << endl;
    else if (s1 == s2)
        cout << "String 1 is equal to String 2" << endl;
    else
        cout << "String 1 is greater than String 2" << endl;

    return 0;
}
