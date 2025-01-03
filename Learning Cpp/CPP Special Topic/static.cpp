#include <bits/stdc++.h>
using namespace std;

class Hero{
    int health;
    public:
    static int TimeToComplete;
    // const static int TimeToComplete = 10;
    // static int TimeToComplete = 10; -> error: ISO C++ forbids in-class initialization of non-const static member ‘Hero::TimeToComplete’
    char level;
    char *name;
    Hero(char *n, char l, int h): name(n), level(l), health(h) {}
    friend ostream& operator<<(ostream& os, const Hero& h);
    static void setHealth(Hero& h, int health) {
        h.health = health;
    }
    static void test() {
        // cout << health << endl; -> error: invalid use of member ‘Hero::health’ in static member function
        cout << TimeToComplete << endl;
    }
};

int Hero::TimeToComplete = 10;

ostream& operator<<(ostream& os, const Hero& h)
{
    // os << "Time to complete: " << h.TimeToComplete << endl; -> not recommended
    os << "Name: " << h.name << endl;
    os << "Level: " << h.level << endl;
    os << "Health: " << h.health << endl;
    return os;
}

int main()
{
    char name[] = "Batman";
    // strcpy(name, "Batman");
    cout << "Time to complete: " << Hero::TimeToComplete << endl;
    Hero h(name, 'A', 100);
    cout << h;
    Hero::test();
    Hero::setHealth(h, 200);
    cout << h;
    return 0;
}