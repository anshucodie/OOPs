#include <iostream>
using namespace std;

class Character {
private:
    char ch;
public:
    Character(char c) : ch(c) {}
    
    char get() const {
        return ch;
    }
    
    friend Character operator!(const Character& obj);
};

Character operator!(const Character& obj) {
    char c = obj.ch;
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    } else if (c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';
    }
    return Character(c);
}

int main() {
    Character obj('f');
    cout << "Original: " << obj.get() << endl;
    
    Character result = !obj;
    cout << "Result: " << result.get() << endl;
    
    Character obj2('Z');
    cout << "Original: " << obj2.get() << endl;
    
    Character result2 = !obj2;
    cout << "Result: " << result2.get() << endl;
    
    return 0;
}