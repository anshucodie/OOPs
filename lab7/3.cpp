#include<iostream>
using namespace std;

class Character{
    char ch;
public:
    Character(char c): ch(c){}
    
     friend Character operator!(Character &c) {
        if(c.ch >= 'a' && c.ch <= 'z')
            c.ch = c.ch - 'a' + 'A'; 
        else if(c.ch >= 'A' && c.ch <= 'Z')
            c.ch = c.ch - 'A' + 'a';
        return c;
    }
    void display(){
        cout<<ch<<endl;
    }
};

int main(){
    Character c1('Z'),c2('c');

    cout<<"Original string: ";c1.display();
    !c1;
    cout<<"After toggle case: ";c1.display();

    cout<<"Original string: ";c2.display();
    !c2;
    cout<<"After toggle case: ";c2.display();

    return 0;
}