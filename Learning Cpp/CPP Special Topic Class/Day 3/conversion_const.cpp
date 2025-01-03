#include <bits/stdc++.h>
using namespace std;

class Test {
    int i;
    public:
    Test(int i):i(i){}
    int get_i(){
        return i;
    }
};

class Test2 {
    int i;
    public:
    Test2():i(0){} // default constructor
    Test2(Test& t): i(t.get_i()){
        cout << "Conversion constructor called" << endl;
    }
    int get_i(){
        return i;
    }
};

int main()
{
    Test t(69);
    Test2 t2;
    cout << typeid(t).name() << endl;
    t2 = t;
    cout << typeid(t2).name() << endl;
    return 0;
}