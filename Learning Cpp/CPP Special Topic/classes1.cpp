#include <bits/stdc++.h>
using namespace std;

struct example {
    short a;
    char b;
}ex1;

class Hero {
    int health;
    public:
    // default constructor
    Hero() {
        health = 100;
        level = 'A';
    }
    // parameterized constructor
    Hero(int h, char l): level(l), health(h) {
        // health = h;
        // level = l;
        cout << "this -> " << this << endl;
        // cout << this->health << endl;
    }
    // copy constructor
    // Hero (Hero h) {
    //     health = h.health;
    //     level = h.level;
    // } -> error because it will call itself
    Hero(const Hero &h) {
        health = h.health;
        level = h.level;
    }

    ~Hero() {
        cout << "Destructor called" << endl;
    }

    char level;

    int get_health() {
        return health;
    }

    void set_health(int h) {
        health = h;
    }

    void print() {
        cout << health << " " << level << endl;
    }
};

int main()
{
    Hero h1(69, 'C'); // static allocation
    // h1.health = 100;
    h1.level = 'A';
    // h1.print();
    // cout << sizeof(ex1) << endl;
    // cout << sizeof(Hero) << endl;
    Hero *h2 = new Hero(90, 'B'); // dynamic allocation
    h2->print();
    cout << h2->get_health() << endl;

    Hero ramesh; // constructor
    Hero *suresh = new Hero();
    //using malloc
    // Hero *suresh2 = (Hero *)malloc(sizeof(Hero));
    // suresh2->print(); // garbage values
    suresh->print();
    cout << suresh << endl;

    return 0;
}