#include<iostream>
using namespace std;

class Vehicle{
    private:
    string brand;
    string model;
    int speed;
    public:

    Vehicle(string b, string m, int s) : brand(b), model(m), speed(s) {}
    virtual void startEngine()=0;
    virtual void stopEngine()=0;

    void setBrand(string b){brand=b;}
    void setModel(string m){model=m;}
    void setSpeed(int s){speed=s;}

    string getBrand() const{return brand;}
    string getModel() const{return model;}
    int getSpeed() const{return speed;}

    virtual ~Vehicle() {}
};

class Maintenance{
public:
    virtual void service()=0;
    virtual void checkOil()=0;
    virtual ~Maintenance() {}
};

class Car: public Vehicle, public Maintenance{
public:  
    Car(string b, string m, int s) : Vehicle(b, m, s) {}

    void startEngine() override {
        cout << "Car engine started for " << getBrand() << " " << getModel() << endl;
    }

    void stopEngine() override {
        cout << "Car engine stopped."<<endl;
    }

    void service(){
        cout<<"Car is being serviced."<<endl;
    }

    void checkOil(){
        cout<<"Car Oil level is checked."<<endl;
    }
};

class Bike : public Vehicle, public Maintenance {
public:
    Bike(string b, string m, int s) : Vehicle(b, m, s) {}

    void startEngine() override {
        cout << "Bike engine started for " << getBrand() << " " << getModel() << endl;
    }

    void stopEngine() override {
        cout << "Bike engine stopped."<<endl;
    }

    void service() override {
        cout << "Bike is being serviced."<<endl;
    }

    void checkOil() override {
        cout << "Bike oil level checked."<<endl;
    }
};

int main(){
    Vehicle* v1= new Car("Mercedes","Benz",220);
    Vehicle* v2 = new Bike("Yamaha", "R15", 150);

    cout << "Car Operations :"<<endl;
    v1->startEngine();
    v1->stopEngine();

    cout << "\nBike Operations :"<<endl;
    v2->startEngine();
    v2->stopEngine();

    
    Car c("BMW", "M5", 170);
    Bike b("Hero", "Splendor", 100);

    cout<<"\nMaintenance tasks:"<<endl;
    c.service();
    c.checkOil();
    b.service();
    b.checkOil();

    
    return 0;
}

