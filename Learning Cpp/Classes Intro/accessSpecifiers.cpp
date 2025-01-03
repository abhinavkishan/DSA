#include<bits/stdc++.h>
using namespace std;

class Complex1 {
    public: double re, im;
    public:
        double norm() { return sqrt(re*re + im*im); }
};

class Complex2 {
    private: double re, im;
    public:
        double norm() { return sqrt(re*re + im*im); }
};

int main() {
    Complex1 t1;
    Complex2 t2;
    // cout << t2.re; -> error
    
}