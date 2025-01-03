#include <bits/stdc++.h>
using namespace std;

class Test1 {
    const int t;
    public:
    Test1(int i): t(i) {}
};

class Test2 {
    int &t;
    public:
    Test2(int &t):t(t){
        // this->t = t; -> gives error: uninitialized reference member in ‘int&’
    }
    int getT() { return t; }
};

// For initializtion of member objects which do not have default constructor
class A {
    public:
    int x;
    // doesnt have default 
    A(int x){this->x = x;}
};

class Test3 {
    public:
    A a;
    Test3(int x): a(x){}
    /* Test3(int x) {
        // error: no matching function for call to ‘A::A()’
        A b(x);
        a = b;
    } */
};

int main()
{
    int x = 20;
    Test2 t1(x);
    cout << t1.getT() << endl;
    x = 30;
    cout << t1.getT() << endl;
    return 0;
}