#include <iostream>
using namespace std;

// Copy constructor is called for call by value and for initialization

class Complex {
    double re, im;
    public:
        Complex(double r, double i) : re(r), im(i) {
            cout << "constructor" << endl;
        }
        Complex(const Complex& c) : re(c.re), im(c.im) {
            cout << "copy constructor" << endl;
        }
};

int main() {
    Complex c1(1, 2); // calls constructor
    Complex c2 = c1; // calls copy constructor
    Complex c3(c1); // calls copy constructor
    // cout << c3.re << endl; // error: re is private
}