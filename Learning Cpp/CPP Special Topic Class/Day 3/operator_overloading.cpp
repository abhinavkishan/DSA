#include <bits/stdc++.h>
using namespace std;

class Complex {
    int real, imag;
    public:
    Complex(int real=0, int imag=0): real(real), imag(imag) {}
    Complex operator+(Complex const& obj) {
        Complex res;// equivalent of malloc, gets allocated from heap
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        // cout << &res;
        return res;
    }
    void print() {
        cout << real << " + i" << imag << '\n';
    }
};

int main()
{
    Complex c1(10,5), c2(2,4);
    Complex c3 = c1 + c2;
    // cout << &c3;
    c3.print();
    return 0;
}