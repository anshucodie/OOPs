#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hour= h;
        minutes= m;
        seconds= s;
    }

    void display() {
        cout << hour << "h " << minutes << "m " << seconds << "s" << endl;
    }

    Time sum(Time t) {
        Time res;
        res.seconds = seconds + t.seconds;
        res.minutes = minutes + t.minutes + res.seconds / 60;
        res.seconds %= 60;
        res.hour = hour + t.hour + res.minutes / 60;
        res.minutes %= 60;
        return res;
    }
};

int main() {
    int h1, m1, s1, h2, m2, s2;

    cout << "Enter time for first object (h m s): ";
    cin >> h1 >> m1 >> s1;
    Time t1(h1, m1, s1);

    cout << "Enter time for second object (h m s): ";
    cin >> h2 >> m2 >> s2;
    Time t2(h2, m2, s2);

    cout << "\nFirst Time: ";
    t1.display();

    cout << "Second Time: ";
    t2.display();

    Time sum = t1.sum(t2);

    cout << "Sum of Times: ";
    sum.display();

    return 0;
}