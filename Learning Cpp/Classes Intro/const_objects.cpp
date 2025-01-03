#include <iostream>
using namespace std;

class MyClass {
    int priv;
    const int cinstData; // const instance data member, should be initialized in the constructor
    public: int pub;
    MyClass(int i) : priv(i), pub(i), cinstData(i) {}
    MyClass() : priv(0), pub(0), cinstData(0) {}
    MyClass(const MyClass& c) : priv(c.getPriv()), pub(c.pub), cinstData(c.cinstData) {} // copy constructor
    int getPriv() const { return priv; }
    void setPriv(int i) { priv = i; }
    // void setConst(int i) { cinstData = i; } -> error: assignment of member 'MyClass::cinstData' in read-only object
    void print() { cout << "priv = " << priv << ", pub = " << pub << endl; }
    void constPrint() const { 
        // priv = 3; -> error: assignment of member 'MyClass::priv' in read-only object
        cout << "Const print:" << endl;
        cout << "priv = " << priv << ", pub = " << pub << endl; 
    }
};

int main() {
    MyClass c1(3);
    c1.print();
    c1.pub = 4;
    c1.print();
    c1.setPriv(5);
    c1.print();

    const MyClass c2(6); // this pointer changes from MyClass* to const MyClass*
    // c2.print(); -> error: passing 'const MyClass' as 'this' argument discards qualifiers
    // c2.print();
    c2.constPrint();
    cout << c2.pub << endl; // we can access pub because it is public, but we cannot call methods that change the object
    c1.constPrint();
    return 0;
}