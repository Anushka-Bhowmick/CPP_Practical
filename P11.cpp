#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}

    void enterDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void printAddress() {
        cout << "Address of the object: " << this << endl;
    }
};

class Student : public Person {
private:
    string studentID;

public:
    void assignRecord() {
        enterDetails();
        cout << "Enter student ID: ";
        cin >> studentID;
    }

    void changeRecord() {
        cout << "Enter new details: " << endl;
        enterDetails();
        cout << "Enter new student ID: ";
        cin >> studentID;
    }

    void deleteRecord() {
        name = "";
        age = 0;
        studentID = "";
    }
};

class Employee : public Person {
private:
    int employeeID;

public:
    void assignRecord() {
        enterDetails();
        cout << "Enter employee ID: ";
        cin >> employeeID;
    }

    void changeRecord() {
        cout << "Enter new details: " << endl;
        enterDetails();
        cout << "Enter new employee ID: ";
        cin >> employeeID;
    }

    void deleteRecord() {
        name = "";
        age = 0;
        employeeID = 0;
    }
};

int main() {
    Person person1, person2;
    cout << "Address of base class object 1: " << &person1 << endl;
    cout << "Address of base class object 2: " << &person2 << endl;
    person1.printAddress();
    person2.printAddress();

    Student student1, student2;
    student1.assignRecord();
    student2.assignRecord();
    cout << "Address of student class object 1: " << &student1 << endl;
    cout << "Address of student class object 2: " << &student2 << endl;
    student1.printAddress();
    student2.printAddress();

    Employee employee1, employee2;
    employee1.assignRecord();
    employee2.assignRecord();
    cout << "Address of employee class object 1: " << &employee1 << endl;
    cout << "Address of employee class object 2: " << &employee2 << endl;
    employee1.printAddress();
    employee2.printAddress();

    return 0;
}
