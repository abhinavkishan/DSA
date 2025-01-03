#include <bits/stdc++.h>
using namespace std;

class Myclass {
    int y;
    public:
    int x;
    void display();
};

//definition outside class
void Myclass::display() {
    cout << x << y;
}

int main()
{
    Myclass example;
    // example.y;
    example.display();
    return 0;
}