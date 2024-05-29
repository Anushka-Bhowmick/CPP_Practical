#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int age;
    string department;
    double salary;

public:
    Employee(const string& n = "", int a = 0, const string& d = "", double s = 0)
        : name(n), age(a), department(d), salary(s) {}

     
    ~Employee() {}

    void setEmployeeInfo(const string& n, int a, const string& d, double s) {
        name = n;
        age = a;
        department = d;
        salary = s;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    string name;
    int age;
    string department;
    double salary;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();  
    cout << "Enter department: ";
    getline(cin, department);
    cout << "Enter salary: ";
    cin >> salary;

    Employee e1(name, age, department, salary);
    e1.display();

    Employee* e2 = new Employee();
    cout << "\nEnter name: ";
    cin.ignore(); 
    getline(cin, name);
    e2->setEmployeeInfo(name, age, department, salary);
    e2->display();
    delete e2;

    return 0;
}
