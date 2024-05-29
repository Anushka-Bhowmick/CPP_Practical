#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    String merge(const String& s) const {
        char* mergedStr = new char[length + s.length + 1];
        strcpy(mergedStr, str);
        strcat(mergedStr, s.str);
        return String(mergedStr);
    }

    ~String() {
        delete[] str;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello, ");
    String s2("world!");

    String merged = s1.merge(s2);
    merged.display();

    return 0;
}
