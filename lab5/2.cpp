#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;
public:
    Student(string n = "", int r = 0) : name(n), rollNo(r) {}
};

class Sports : virtual public Student {
protected:
    int s_grade;
public:
    Sports(string n = "", int r = 0, int sg = 0) : Student(n, r), s_grade(sg) {}
};


class Exam : virtual public Student {
protected:
    int e_grade;
public:
    Exam(string n = "", int r = 0, int eg = 0) : Student(n, r), e_grade(eg) {}
};


class Results : public Sports, public Exam {
    string finalResult;
public:
    Results(string n, int r, int sg, int eg, string fr)
        : Student(n, r), Sports(n, r, sg), Exam(n, r, eg), finalResult(fr) {}


    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Sports Grade: " << s_grade << endl;
        cout << "Exam Grade: " << e_grade << endl;
        cout << "Final Result: " << finalResult << endl;
    }
};

int main() {
    Results r1("Bob", 101, 85, 90, "Pass with Distinction");

    cout << "Final Student Record:" << endl;
    r1.display();

    return 0;
}
