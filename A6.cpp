#include <iostream>
#include <string>
using namespace std;

class EmployeeReport {
private:
    int employeeID;
    double totalBonus;
    double totalOvertime;

public:
    EmployeeReport() : employeeID(0), totalBonus(0), totalOvertime(0) {}

    EmployeeReport(int id, double bonus, double overtime) 
        : employeeID(id), totalBonus(bonus), totalOvertime(overtime) {}

    void setPara(int id, double bonus, double overtime) {
        employeeID = id;
        totalBonus = bonus;
        totalOvertime = overtime;
    }

    void setPara() {
        employeeID = 0;
        totalBonus = 0;
        totalOvertime = 0;
    }

    void displayReport() const {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Total Bonus: $" << totalBonus << endl;
        cout << "Total Overtime: " << totalOvertime << " hours" << endl;
    }
};

int main() {
    EmployeeReport emp1(101, 5000.0, 20.5);
    EmployeeReport emp2;
    emp2.setPara(102, 7000.0, 25.0);
    EmployeeReport emp3;
    emp3.setPara(103, 6000.0, 22.0);
    EmployeeReport emp4;
    emp4.setPara(104, 5500.0, 21.0);

    emp1.displayReport();
    emp2.displayReport();
    emp3.displayReport();
    emp4.displayReport();

    return 0;
}
