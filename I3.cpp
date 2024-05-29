#include <iostream>
#include <string>

class PERSON {
protected:
    std::string name;
    std::string college;

public:
    PERSON(const std::string& n, const std::string& c) : name(n), college(c) {}

    void setName(const std::string& n) { name = n; }
    void setCollege(const std::string& c) { college = c; }

    std::string getName() const { return name; }
    std::string getCollege() const { return college; }
};

class STUDENT : public PERSON {
private:
    std::string student_id;
    int marks[5];
    float percentage;

public:
    STUDENT(const std::string& n, const std::string& c, const std::string& id)
        : PERSON(n, c), student_id(id), percentage(0.0f) {
        for (int i = 0; i < 5; ++i) {
            marks[i] = 0;
        }
    }

    void setStudentId(const std::string& id) { student_id = id; }

    void setMarks(int subject_marks[5]) {
        for (int i = 0; i < 5; ++i) {
            marks[i] = subject_marks[i];
        }
    }

    void showResult() {
        int total = 0;
        for (int i = 0; i < 5; ++i) {
            total += marks[i];
        }
        percentage = (float)total / 5.0f;

        std::cout << "Student ID: " << student_id << std::endl;
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "College: " << getCollege() << std::endl;
        std::cout << "Total Marks: " << total << std::endl;
        std::cout << "Percentage: " << percentage << "%" << std::endl;

        std::string grade = (percentage >= 75.0f) ? "Distinction"
                           : (percentage >= 60.0f) ? "First Class"
                           : (percentage >= 50.0f) ? "Second Class"
                           : (percentage >= 35.0f) ? "Pass"
                           : "Fail";

        std::cout << "Class: " << grade << std::endl;
    }
};

class EMPLOYEE : public PERSON {
private:
    std::string emp_id;
    std::string qualification;
    float basic_salary;

public:
    EMPLOYEE(const std::string& n, const std::string& c, const std::string& id, const std::string& qual, float salary)
        : PERSON(n, c), emp_id(id), qualification(qual), basic_salary(salary) {}

    void setEmpId(const std::string& id) { emp_id = id; }
    void setQualification(const std::string& qual) { qualification = qual; }
    void setBasicSalary(float salary) { basic_salary = salary; }

    void showNetSalary() {
        float da = 0.189f * basic_salary;
        float hra = 0.10f * basic_salary;
        float ta = 500.0f;
        float income_tax = (basic_salary > 50000.0f) ? 0.05f * basic_salary : 0.0f;
        float net_salary = basic_salary + da + hra + ta - income_tax;

        std::cout << "Employee ID: " << emp_id << std::endl;
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "College: " << getCollege() << std::endl;
        std::cout << "Qualification: " << qualification << std::endl;
        std::cout << "Basic Salary: " << basic_salary << std::endl;
        std::cout << "DA: " << da << std::endl;
        std::cout << "HRA: " << hra << std::endl;
        std::cout << "TA: " << ta << std::endl;
        std::cout << "Income Tax: " << income_tax << std::endl;
        std::cout << "Net Salary: " << net_salary << std::endl;
    }
};

int main() {
    std::string student_name, student_college, student_id;
    int student_marks[5];

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, student_name);
    std::cout << "Enter Student College: ";
    std::getline(std::cin, student_college);
    std::cout << "Enter Student ID: ";
    std::getline(std::cin, student_id);

    std::cout << "Enter marks for 5 subjects: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> student_marks[i];
    }

    STUDENT student(student_name, student_college, student_id);
    student.setMarks(student_marks);

    std::cout << "\nStudent Details:" << std::endl;
    student.showResult();

    std::cout << std::endl;

    std::string employee_name, employee_college, emp_id, qualification;
    float basic_salary;

    std::cout << "Enter Employee Name: ";
    std::cin.ignore();
    std::getline(std::cin, employee_name);
    std::cout << "Enter Employee College: ";
    std::getline(std::cin, employee_college);
    std::cout << "Enter Employee ID: ";
    std::getline(std::cin, emp_id);
    std::cout << "Enter Qualification: ";
    std::getline(std::cin, qualification);
    std::cout << "Enter Basic Salary: ";
    std::cin >> basic_salary;

    EMPLOYEE employee(employee_name, employee_college, emp_id, qualification, basic_salary);

    std::cout << "\nEmployee Details:" << std::endl;
    employee.showNetSalary();

    return 0;
}
