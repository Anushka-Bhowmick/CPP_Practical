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
    Employee(const string& n = "", int a = 0, const string& d = "", double s = 0) : name(n), age(a), department(d), salary(s) {}

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
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    // Static initialization of objects
    Employee emp1("John", 30, "HR", 50000.0);
    Employee emp2("Alice", 25, "IT", 60000.0);

    // Display information for static objects
    cout << "Static Initialization:" << endl;
    cout << "Employee 1:" << endl;
    emp1.display();
    cout << endl;
    cout << "Employee 2:" << endl;
    emp2.display();
    cout << endl;

    // Dynamic initialization of objects
    cout << "Dynamic Initialization:" << endl;
    Employee* empArray = new Employee[n];
    for (int i = 0; i < n; ++i) {
        string name, department;
        int age;
        double salary;

        cout << "Enter information for Employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Department: ";
        cin >> department;
        cout << "Salary: ";
        cin >> salary;

        empArray[i].setEmployeeInfo(name, age, department, salary);
    }

    // Display information for dynamic objects
    for (int i = 0; i < n; ++i) {
        cout << "Employee " << i + 1 << ":" << endl;
        empArray[i].display();
        cout << endl;
    }

    delete[] empArray;

    return 0;
}
