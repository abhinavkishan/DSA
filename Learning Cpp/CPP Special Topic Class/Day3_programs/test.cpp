#include <bits/stdc++.h>
using namespace std;

class Base {
    int z;
    protected:
    int x;
    public:
    int y;
    Base():x(10),y(69){}
};

class Child: public Base{
    int a;
    public:
    Child():a(690){}
    void display() {
        // cout << x << y << z  << a << endl; z -> inaccessible
        cout << x << y << a << endl;
    }
};

int main()
{
    Child c;
    c.display();
    c.y;
    return 0;
}