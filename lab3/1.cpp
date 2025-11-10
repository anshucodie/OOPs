#include<iostream>
using namespace std;

class Circle{
public:
int radius;

void areaOfCircle(int radius){
this->radius=radius;
float area=3.14*radius*radius;
cout<<"The area is: "<<area<<endl;
}
};

class Rectangle: public Circle{
    public:
    int breadth;
    void areaOfRectangle(int breadth){
        int area= radius*breadth;
        cout<<"The area of rectangle is: "<<area<<endl;
    }
};

int main(){
    int radius;
    int breadth;
    Rectangle r;
    cout<<"Enter the value of radius: "<<endl;
    cin>>radius;
    r.areaOfCircle(radius);
    cout<<"Enter the value of breadth for the rectangle: "<<endl;
    cin>>breadth;
    r.areaOfRectangle(breadth);

    return 0;
}