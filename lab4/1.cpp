#include<iostream>
#include<string>

using namespace std;

class Person{
public:

    string name;
    int age;
    Person(){
        name="Unknown";
        age=0;
    }
    void setPerson(string inputName,int age){
        name=inputName;
        this->age=age;
    }
    void displayPerson(){
        cout<<"The name is "<< name<<" and the age is "<<age<<endl;
    }
};

class Student:virtual public Person{
public:

    int rollno;
    string course;
    Student(){
        rollno=0;
        course="Engineering";
    }
    void setStudent(int roll,string course){
        rollno=roll;
        this->course=course;
    }

    void displayStudent(){
        cout<<"Roll no. of "<<name<<"is "<<rollno<<" and the course opted is "<<course<<endl;
    }
};

class Faculty:virtual public Person{
public:

    int facultyid;
    string department;

    Faculty(){
        facultyid=0;
        department="Assitant Prof";
    }

    void setFaculty(int id,string depart){
        facultyid=id;
        department=depart;
    }
    void displayFaculty(){
        cout<<"The id of faculty is "<<facultyid<<"and the department is "<<department<<endl;
    }
};

class TeachingAssistant:virtual public Student, virtual public Faculty{
public:

    int hoursPerWeek;
    TeachingAssistant(){
        hoursPerWeek=0;
    }

    void setTA(string n, int a, int roll, string c, int id, string dept,int hrpweek){
        hoursPerWeek=hrpweek;
        setPerson(n,a);
        setStudent(roll,c);
        setFaculty(id,dept);
    }
    void displayTA(){
        displayPerson();
        displayStudent();
        displayFaculty();
        cout<<"The teaching assistant works "<<hoursPerWeek<<" hours in a day"<<endl;
    }
};

int main(){
    TeachingAssistant TA;
    
    TA.setTA("Liza", 18, 95, "Computer Science", 5001, "CSE Department", 7);
    TA.displayTA();
}