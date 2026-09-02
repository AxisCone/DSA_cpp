#include <iostream>
using namespace std;

class person {
protected:
    string name;

public:
    void showName() {
        cout << "Hi, My name is " << name << endl;
    }

    person(string name) {
        this->name = name;
    }
};

class employee : public person {
protected:
    float salary;

public:
    void showSalary() {
        cout << "Salary: " << salary << endl;
    }

    employee(string name, float salary)
        : person(name)
    {
        this->salary = salary;
    }
};

class manager : public employee {
protected:
    string department;

public:
    void showDepartment() {
        cout << "Department: " << department << endl;
    }

    manager(string name, float salary, string department)
        : employee(name, salary)
    {
        this->department = department;
    }
};

int main() {

    manager m("Rahul", 80000, "IT");

    m.showName();
    m.showSalary();
    m.showDepartment();

    return 0;
}