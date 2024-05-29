#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

class staff {
public:
    int code;
    char name[100];

    void set_info(const char* n, int c) {
        strcpy(name, n);
        code = c;
    }
};

class teacher : public staff {
protected:
    char sub[100], publication[100];

public:
    void set_details(const char* s, const char* p) {
        strcpy(sub, s);
        strcpy(publication, p);
    }

    void show() {
        cout << setw(10) << "name" << setw(8) << "code" << setw(15) << "subject" << setw(25)
             << "publication" << endl;
        cout << setw(10) << name << setw(8) << code << setw(15) << sub << setw(25) << publication << endl;
    }
};

class officer : public staff {
    char grade[100];

public:
    void set_details(const char* g) {
        strcpy(grade, g);
    }

    void show() {
        cout << setw(10) << "name" << setw(8) << "code" << setw(15) << "grade" << endl;
        cout << setw(10) << name << setw(8) << code << setw(15) << grade << endl;
    }
};

class typist : public staff {
protected:
    float speed;

public:
    void set_speed(float s) {
        speed = s;
    }
};

class regular : public typist {
    float wage;

public:
    void set_wage(float w) {
        wage = w;
    }

    void show() {
        cout << setw(10) << "name" << setw(8) << "code" << setw(10) << "speed" << setw(10)
             << "wage" << endl;
        cout << setw(10) << name << setw(8) << code << setw(10) << speed << setw(10) << wage << endl;
    }
};

class casual : public typist {
    float wage;

public:
    void set_wage(float w) {
        wage = w;
    }

    void show() {
        cout << setw(10) << "name" << setw(8) << "code" << setw(10) << "speed" << setw(10)
             << "wage" << endl;
        cout << setw(10) << name << setw(8) << code << setw(10) << speed << setw(10) << wage << endl;
    }
};

int main() {
    teacher t;
    t.set_info("Teacher", 420);
    t.set_details("Subject publication", "C++");

    officer o;
    o.set_info("Officer", 222);
    o.set_details("First class");

    regular rt;
    rt.set_info("Regular Typist", 333);
    rt.set_speed(85.5);
    rt.set_wage(15000);

    casual ct;
    ct.set_info("Casual Typist", 334); 
    ct.set_speed(78.9);
    ct.set_wage(10000);

    cout << "About teacher:" << endl;
    t.show();
    cout << "About officer:" << endl;
    o.show();
    cout << "About regular typist:" << endl;
    rt.show();
    cout << "About casual typist:" << endl;
    ct.show();

    return 0;
}
