// order of init matters on declaration order 

#include <iostream>
using namespace std;

int init_v1(int v) {
    cout << "init_v1" << endl;
    return v;
}

int init_v2(int v) {
    cout << "init_v2" << endl;
    return v;
}

class Order1 {
    int v1;
    int v2;
public:
    Order1() : v1(init_v1(1)), v2(init_v2(2)) {
        cout << "Order1" << endl;
    }
};

class Order2 {
    int v2; int v1;
public:
    Order2() : v1(init_v1(1)), v2(init_v2(2)) {
        cout << "Order2" << endl;
    }
};

int main() {
    Order1 o1;
    Order2 o2;
}