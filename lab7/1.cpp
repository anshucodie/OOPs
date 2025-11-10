#include<iostream>
using namespace std;

class Fraction{
    int numerator, denomenator;
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    void simplify(){
        int n=gcd(numerator,denomenator);
        numerator/=n;
        denomenator/=n;
        if(denomenator<0){
            numerator= -numerator;
            denomenator= -denomenator;
        }
    }
public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denomenator = (d == 0) ? 1 : d;
        simplify();
    }

    friend Fraction operator+(Fraction a, Fraction b) {
        Fraction res(a.numerator * b.denomenator + b.numerator * a.denomenator, a.denomenator * b.denomenator);
        res.simplify();
        return res;
    }
    friend Fraction operator-(Fraction a, Fraction b) {
        Fraction res(a.numerator * b.denomenator - b.numerator * a.denomenator, a.denomenator * b.denomenator);
        res.simplify();
        return res;
    }
    friend Fraction operator*(Fraction a, Fraction b) {
        Fraction res(a.numerator * b.numerator, a.denomenator * b.denomenator);
        res.simplify();
        return res;
    }
    Fraction operator/(Fraction b){
        Fraction res(numerator*b.denomenator,denomenator*b.numerator);
        res.simplify();
        return res;   
    }
    void display() {
        cout << numerator << "/" << denomenator << endl;
    }
};

    int main(){
    Fraction f1(2, 4), f2(3, 7);
    Fraction f3;

    cout << "f1 = "; f1.display();
    cout << "f2 = "; f2.display();

    f3 = f1 + f2; cout << "f1 + f2 = "; f3.display();
    f3 = f1 - f2; cout << "f1 - f2 = "; f3.display();
    f3 = f1 * f2; cout << "f1 * f2 = "; f3.display();
    f3 = f1 / f2; cout << "f1 / f2 = "; f3.display();

    return 0;
    }