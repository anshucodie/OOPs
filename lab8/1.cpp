#include<iostream>
using namespace std;

class Drone{
    protected:
    const string droneID;
    int batteryLevel;

    public:
    static int totalDeliveries; 

    static void increment() {
        totalDeliveries++;
    }

    static void showTotaldeliveries() {
        cout << "Total Deliveries: " << totalDeliveries << endl;
    }

    Drone(string id, int battery) : droneID(id), batteryLevel(battery) {}

    virtual void deliverPackage()=0;

    void setBatteryLevel(int battery) { 
        batteryLevel = battery;
     }
    int getBatteryLevel() { 
        return batteryLevel; 
    }

};

class CityDrone:virtual public Drone{
    public:
    CityDrone(string id, int battery) : Drone(id, battery) {}

    void deliverPackage(){
    cout<<droneID<<"\tDelivered within city limits"<<endl;
    batteryLevel-=5;
    }
};

class InterCityDrone: public Drone{
    public:
    InterCityDrone(string id, int battery) : Drone(id, battery) {}

    void deliverPackage(){
    cout<<droneID<<"\tDelivered to other city"<<endl;
    batteryLevel-=10;
    }
};

int Drone::totalDeliveries = 0;

class Package final {
public:
    string packageID;
    int weight;
    string destination;

    Package(string id, int w, string dest) : packageID(id), weight(w), destination(dest) {}
};


int main(){
    CityDrone d1("Liza",97);
    InterCityDrone d2("Abc",98);
    InterCityDrone d3("Lmn",95);

    Package p1("Liza",45,"Gandhinagar");
    Package p2("Abc",45,"Rajkot");
    Package p3("Lmn",45,"Surat");

    d1.deliverPackage();
    Drone::increment();
    Drone::showTotaldeliveries();

    d2.deliverPackage();
    Drone::increment();
    Drone::showTotaldeliveries();

    d3.deliverPackage();
    Drone::increment();
    Drone::showTotaldeliveries();

    
    return 0;
}