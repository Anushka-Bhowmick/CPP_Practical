#include<iostream>
#include<string>
using namespace std;
class EmployeeReport{
    private:
    int employeeId;
    double totalBonus, totalOvertime;
    public:
    EmployeeReport(){
        employeeId = 0;
        totalBonus = 0;
        totalOvertime = 0;
    }
    EmployeeReport(int id, double bonus, double overtime){
        employeeId = id;
        totalBonus = bonus;
        totalOvertime = overtime;
    }
    void setPara(int id, double bonus, double overtime){
        employeeId = id;
        totalBonus = bonus;
        totalOvertime = overtime;
    }
    void setPara(){
        employeeId = 0;
        totalBonus = 0;
        totalOvertime = 0;
    }
    void displayReport(){
        cout<<"Employee ID: "<<employeeId<<endl;
        cout<<"Total Bonus: "<<totalBonus<<endl;
        cout<<"Total Overtime: "<<totalOvertime<<endl;
    }
};
int main(){
    int id;
    double bonus, overtime;
    cout<<"Enter the employee ID: "<<endl;
    cin>>id;
    cout<<"Enter the total bonus: "<<endl;
    cin>>bonus;
    cout<<"Enter the total overtime: "<<endl;
    cin>>overtime;
    EmployeeReport e1(id, bonus, overtime);
    e1.displayReport();
    EmployeeReport e2;
    e2.setPara(1, 1000, 10);
    e2.displayReport();
    e2.setPara();
    e2.displayReport();
    return 0;

}