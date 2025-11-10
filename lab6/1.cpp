#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
    string vehicleName;
    public:
    Vehicle(string vehName){
        vehicleName=vehName;
    }
    virtual int calculateFare()=0;
    virtual void display(){
        cout<<"The Vehicle's Name is:"<<vehicleName<<endl;
    }
};

class Bus: public Vehicle{
    public:

    int distance;
    int farePerKm;

    public: 
    Bus(string name,int d,int fpkm):Vehicle(name),distance(d),farePerKm(fpkm){}
    int calculateFare() override{
        int fare= distance*farePerKm;
        return fare;
    }
    Bus operator+(Bus &b){
        int totald= this->distance+b.distance;
        int fare= this->calculateFare()+b.calculateFare();
        return Bus("Combined",distance,fare);
    }
    void display() override {
        cout << "Bus: " << vehicleName <<endl
             << "Distance: " << distance<<endl
             << "Fare/Km: " << farePerKm <<endl
             << "Total Fare: " << calculateFare() 
             << endl;
    }
};

class Taxi: public Vehicle{
    protected:
    int hours;
    int ratePerHour;
    public:
    Taxi(string name,int hrs,int rph):Vehicle(name),hours(hrs),ratePerHour(rph){}
    int calculateFare()override{
        int fare= hours*ratePerHour;
        return fare;
    }

    void display() override {
        cout << "Taxi: " << vehicleName<<endl 
             << "Hours: " << hours<<endl
             << "Rate/Hour: " << ratePerHour<<endl
             << "Total Fare: " << calculateFare() 
             << endl;
    }
};

int main(){
    Bus b1("Volvo",010, 20);
    Bus b2("Mercedes",12, 20);
    Taxi t("Desire",2,60);

    Vehicle* v1 = &b1;
    Vehicle* v2 = &b2;
    Vehicle* v3 = &t;

    v1->display();
    v2->display();
    v3->display();

    Bus combined= b1+b2;
    cout << "After combining two buses:" << endl;
    combined.display();

}


