#include <bits/stdc++.h>
using namespace std;

class parent {
    public:
    int x, y;
    void display() {
        cout << x << y << endl;
    }
};

class child: public parent {
    public:
    int z;
    void display() {
        cout << x << y << z << endl;
    }
};

int main()
{
    child c;
    parent *ptr = &c; // -> does not work if derived as private
    ptr->display();
    c.display();
    c.parent::display();
    return 0;
}