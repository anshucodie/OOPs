#include<iostream>
using namespace std;

class Shape {
public:
    double a, b;

    void getData() {
        cout << "Enter first dimension: ";
        cin >> a;
        cout << "Enter second dimension: ";
        cin >> b;
    }
    virtual void displayArea()=0;
};

class Triangle : public Shape {
public:
    void displayArea() {
        double area = 0.5 * a * b;
        cout << "Area of Triangle is:  " << area << endl;
    }
};

class Rectangle : public Shape {
public:
    void displayArea() {
        double area = a * b;
        cout << "Area of Rectangle is:  " << area << endl;
    }
};

int main() {
    int choice;
    cout << "Choose Shape (1. Triangle  2. Rectangle): ";
    cin >> choice;

    Shape* shape = nullptr;
    if (choice == 1)
        shape = new Triangle();
    else if (choice == 2)
        shape = new Rectangle();
    else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    shape->getData();
    shape->displayArea();

    delete shape;
    return 0;
}
