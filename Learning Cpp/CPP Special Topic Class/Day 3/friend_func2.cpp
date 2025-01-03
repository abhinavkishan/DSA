#include <bits/stdc++.h>
using namespace std;

class B; // forward declaration

class A {
    private:
        int a;
    public:
        A(int a = 0): a(a) {}
        friend void display(A,B); // Friend Class
};

class B {
    private:
        int b;
    public:
        B(int b = 0): b(b) {}
        friend void display(A,B); // Friend Class
};

void display(A obj1, B obj2) {
    cout << "Sum of data members of A and B is: " << obj1.a + obj2.b << endl;
}

int main()
{
    A a(69);
    B b(69);
    display(a, b);
    return 0;
}