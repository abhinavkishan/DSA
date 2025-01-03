#include <bits/stdc++.h>
using namespace std;

class test {
    int x, y, z;
    public:
    test(int x) { 
        cout << "Constructor 1 is called!" << endl;
        this->x = x;
    }
    test(int x, int y): test(x) {
        cout << "Constructor 2 is called!" << endl;
        this->x = x; this->y = y;
    }
    test(int x, int y, int z):test(x,y):test(x) {
        cout << "Constructor 3 is called!" << endl;
        this->z = z;
    }
};

int main()
{
    test t1(1,2,3); 
    return 0;
}