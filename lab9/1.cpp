#include<iostream>
using namespace std;

class Shape{
private:
    double radius;
    double sidelength;
public:
    virtual double Area()= 0;
    virtual void show(){
        cout<<"The area is : "<< Area() <<endl;
    }

    void setDimension(double r) { radius = r; }
    void setDimension(double s, bool isSquare) {
        if(isSquare){
         sidelength = s; }
        }

    double getRadius() const{return radius;}
    double getSide() const{return sidelength;}
};

class Circle: virtual public Shape{
    public:
    double Area() override {
        return 3.14 * getRadius() * getRadius();
    }

    void show() override {
        cout << "Circle Area: " << Area() << endl;
    }
};

class Square: virtual public Shape{
    public:
    double Area() override {
        return getSide() * getSide();
    }

    void show() override {
        cout << "Square Area: " << Area() << endl;
    }
};

int main() {
    Shape* shape;

    Circle c;
    c.setDimension(5);
    shape = &c;
    shape->show();

    Square s;
    s.setDimension(4,true);
    shape = &s;
    shape->show();

    return 0;
}