#include<iostream>
using namespace std;

class Employee {
protected:
    string name;
    int empid;
    double baseSalary;

public:
    Employee(string n, int id, double sal) : name(n), empid(id), baseSalary(sal) {}

    virtual void displayDetails() {
        cout << "Name: " << name << ", EmpID: " << empid << ", Base Salary: " << baseSalary << endl;
    }

    virtual double calculateSalary() = 0;
    virtual ~Employee() {}
};

class TaxDetails {
public:
    virtual double taxCalculation(double salary) = 0;
    virtual ~TaxDetails() {}
};

class FullTimeEmployee : public Employee, public TaxDetails {
    double hra;
    double transport;

public:
    FullTimeEmployee(string n, int id, double sal, double hra, double transport)
        : Employee(n, id, sal), hra(hra), transport(transport) {}

    double calculateSalary() override {
        return baseSalary + hra + transport;
    }

    double taxCalculation(double salary) override {
        return salary * 0.10;
    }

    void displayDetails() override {
        double salary = calculateSalary();
        cout << "\nFull-Time Employee"<<endl;
        Employee::displayDetails();
        cout << "Allowance(hra+transport): " << hra+transport<<endl
             << "Total Salary: " << salary <<endl
             << "Tax: " << taxCalculation(salary) << endl;
    }
};

class PartTimeEmployee : public Employee, public TaxDetails {
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(string n, int id,int sal, int hours, double rate)
        : Employee(n, id, sal), hoursWorked(hours), hourlyRate(rate) {}

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    double taxCalculation(double salary) override {
        return salary * 0.05; 
    }

    void displayDetails() override {
        double salary = calculateSalary();
        cout << "\nPart-Time Employee"<<endl;
        Employee::displayDetails();
        cout << "Hours Worked: " << hoursWorked<<endl
             << "Hourly Rate: " << hourlyRate<<endl
             << "Total Salary: " << salary<<endl
             << "Tax: " << taxCalculation(salary) << endl;
    }
};

class Intern : public Employee, public TaxDetails {
    double stipend;

public:
    Intern(string n, int id,int sal, double stip)
        : Employee(n, id, sal), stipend(stip) {}

    double calculateSalary() override {
        return stipend;
    }

    double taxCalculation(double salary) override {
        return salary * 0.02; 
    }

    void displayDetails() override {
        double salary = calculateSalary();
        cout << "\nIntern"<<endl;
        Employee::displayDetails();
        cout << "Stipend: " << stipend<<endl
             << "Total Salary: " << salary<<endl
             << "Tax: " << taxCalculation(salary) << endl;
    }
};

int main(){
    Employee* e1 = new FullTimeEmployee("Alice", 101, 50000, 10000,7000);
    Employee* e2 = new PartTimeEmployee("Bob", 102,20000, 80, 200);
    Employee* e3 = new Intern("Charlie", 4000, 103, 10000);

    e1->displayDetails();
    e2->displayDetails();
    e3->displayDetails();

    return 0;
}