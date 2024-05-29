#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : virtual public Person {
public:
    int employeeID;
    Employee(string n, int a, int id) : Person(n, a), employeeID(id) {}
    void display() {
        Person::display();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Student : virtual public Person {
public:
    int studentID;
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}
    void display() {
        Person::display();
        cout << "Student ID: " << studentID << endl;
    }
};

class Manager : public Employee, public Student {
public:
    Manager(string n, int a, int eid, int sid) : Person(n, a), Employee(n, a, eid), Student(n, a, sid) {}
    void display() {
        Employee::display();
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Manager mgr("Alice", 30, 1001, 2001);
    mgr.display();
    return 0;
}
