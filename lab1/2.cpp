#include <iostream>
using namespace std;

class Box {
    public:
        int l;
        int h;
        int b;

    void inp(){
        cout << "Enter length : ";
        cin >> l;

        cout << "Enter width : ";
        cin >> b;

        cout << "Enter height : ";
        cin >> h;
    }

    float vol(){
        return l*b*h;
    }
};

int main (){
    Box box[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "For box " << i+1 << endl;
        box[i].inp();
        float x = box[i].vol();
        cout << "Vol of box " << i + 1 << " is " << x << endl;

    }
    return 0;
}