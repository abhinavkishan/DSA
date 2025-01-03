#include <bits/stdc++.h>
using namespace std;

class Hero{
    int health;
    public:
    char *name;
    char level;
    friend int get_health(Hero h);
    Hero() {
       cout << "Default constructor called" << endl;
       name = new char[10]; 
    }

    Hero(Hero &h):health(h.health), level(h.level) {
        cout << "Copy constructor called" << endl;
        this->name = new char[10];
        strcpy(this->name, h.name);
    }

    void set_health(int h) {
        health = h;
    }

    void set_name(char *n) {
        strcpy(name, n);
    }

    void print() {
        cout << health << " " << level << endl;
    }

    friend ostream& operator << (ostream &os, Hero &h) {
        os << "Name: " << h.name << endl;
        os << "Health: " << h.health << endl;
        os << "Level: " << h.level << endl;
        os << "Address: " << &h << endl;
        // os << "name address: " << &h.name << endl;
        return os;
    }

    ~Hero() {
        cout << "Destructor called" << endl;
        delete [] name;
    }

};

int get_health(Hero h) {
    return h.health;
}

int main()
{
    {
        Hero *h3 = new Hero();
        // manually calling destructor -> for dynamic allocation
        delete h3;
    }
    Hero h1;
    h1.set_health(69);
    char n[] = "Hero 1";
    h1.set_name(n);
    h1.level = 'A';
    cout << h1 << endl;

    // Hero h2(h1); // -> default copy constructor -> shallow copy
    Hero h2 = h1; // -> default copy constructor -> shallow copy
    cout << h2 << endl;
    cout << (void *) h2.name << endl;
    cout << (void *) h1.name << endl;

    char n2[] = "Hero 2";
    h2.set_name(n2);
    cout << h1 << endl;
    cout << h2 << endl;

    cout << (void *) h2.name << endl;
    cout << (void *) h1.name << endl;

    // address pointed by char

    /*strcpy(n, "Hero 2");
    h1.set_name(n);
    cout << h1 << endl;
    cout << h2 << endl;

    // will not change health as its not dynamic
    h1.set_health(100);
    cout << h1 << endl;
    // h2 health will also change
    cout << h2 << endl;
    // cout << h3 << endl;*/
    return 0;
}