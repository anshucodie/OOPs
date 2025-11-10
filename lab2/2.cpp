#include<iostream>
using namespace std;

class Person{
    public:
    string name;
    string city;

    void setName(string inputName){
        name=inputName;
    }
    void displayName(){
        cout<<"The name is: "<< name<<endl;
    }

    void setCity(string city){
        this->city=city;
    }
    void displayCity(){
        cout<<name<<" lives in "<<city<<endl;
    }
};

class Employee{
    public:
    int salary;

    void setSalary(int sal){
        salary=sal;
    }

    void displaySalary(string name){
        cout<< "The salary of "<< name <<" is:"<<salary<<endl;
    }
};

int main(){
    Employee e;
    Person p;
    
    string name;
    cout<<"Enter your name:"<<endl;
    cin>>name;
    string city;
    cout<<"Enter your city:"<<endl;
    cin>>city;

    p.setName(name);
    p.setCity(city);
    e.setSalary(50000);
    p.displayName();
    p.displayCity();
    e.displaySalary(name);

    return 0;
}