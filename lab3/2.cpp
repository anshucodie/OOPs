#include <iostream>
#include <string>
using namespace std;

class STUDENT {
public:
    int rollNo;
    string name;
    int age;


    void getData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    int getAge() {
        return age;
    }

    void display() {
        cout << "Roll No: " << rollNo 
             << ", Name: " << name 
             << ", Age: " << age;
    }
};

class UGSTUDENT : public STUDENT {
public:
    int semester;
    float fees;
    float stipend;

    void getUGData() {
        getData();
        cout << "Enter Semester: ";
        cin >> semester;
        cout << "Enter Fees: ";
        cin >> fees;
        cout << "Enter Stipend: ";
        cin>>stipend;
    }

    void displayUG() {
        display();
        cout << ", Semester: " << semester 
             << ", Fees: " << fees 
             << ", Stipend: " << stipend << endl;
    }
};

int main() {
    int n = 5;
    UGSTUDENT students[5];
    cout << "Enter details of " << n << " UG Students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].getUGData();
    }

    cout << "\nDetails of UG Students:\n";
    int totalAge = 0;
    for (int i = 0; i < n; i++) {
        students[i].displayUG();
        totalAge += students[i].getAge();
    }

    cout << "\nAverage Age of UG Students = " 
         << (float)totalAge / n << endl;

    return 0;
}
