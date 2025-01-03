#include <iostream>
using namespace std;

// copy constructor must have parameter of type const reference otherwise its recursive call

class Complex {
    double re, im;
    public:
        Complex(double r, double i) : re(r), im(i) {}
        Complex() : re(0), im(0) {}
        Complex(const Complex& c) : re(c.re), im(c.im) { cout << "Copy constructor called" << endl; }
        ~Complex() { cout << "Destructor called" << endl; }
        double real() const { return re; }
        void real(double d) { re = d; }
        double imag() const { return im; }
        void imag(double d) { im = d; }
        void print() { cout << re << " + " << im << "i" << endl; }
};

Complex Display(Complex c) {
    c.print();
    return c;
}

int main() {
    Complex c1(3, 4);
    Complex c2 = Display(c1);
    return 0;
}