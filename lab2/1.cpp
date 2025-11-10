#include<iostream>
using namespace std;

class Person{
    public:
    string name;

    void setName(string inputName){
        name=inputName;
    }
    void displayName(){
        cout<<"The name is: "<< name<<endl;
    }
};

class Employee: public Person{
    public:
    int salary;

    void setSalary(int sal){
        salary=sal;
    }

    void displaySalary(){
        cout<< "The salary of "<< name <<" is:"<<salary<<endl;
    }
};

int main(){
    Employee e;

    e.setName("Liza");
    e.setSalary(50000);
    e.displayName();
    e.displaySalary();

    return 0;
}