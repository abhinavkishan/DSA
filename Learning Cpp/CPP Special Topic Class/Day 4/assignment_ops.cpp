#include <bits/stdc++.h>
using namespace std;

class Point {
    int x = 10;
    int y = 10;
    public:
    Point(){}
    Point(int x, int y):x(x), y(y) {
        cout << "Constructor called!" << endl;
    }
    Point(const Point& p) {
        cout << "Copy Constructor called!" << endl;
        x = p.x;
        y = p.y;
    }

    Point(Point && p) {
        cout << "Move Constructor called!" << endl;
        x = p.x;
        y = p.y;
    }

    Point & operator=(const Point &p) {
        cout << "Copy assignment operator called\n";
        x = p.x;
        y = p.y;
        return *this;
    }
    Point & operator=(Point &&p) {
        cout << "Move assignment operator called\n";
        x = p.x;
        y = p.y;
        return *this;
    }
    friend ostream & operator<<(ostream &os, const Point &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

Point random(int x, int y) {
    return Point(x, y);
}


int main()
{
    // int a = 10;
    // int &&x = 10; // -> rvalue reference to a temporary object
    // cout << x << endl;
    // // Point p1(10, 20);
    // Point p1;
    // cout << p1 << endl;
    // Point p2(30, 40);
    // Point p3 = p2; // Point p3(p2);
    // p1 = p2; // copy assignment operator
    // cout << p1 << endl;
    // p1 = Point(50, 60); // move assignment operator
    // Point p1(move(Point(1,2)));
    // p1 = Point(1,2);
    Point p2(1,2);
    p2 = random(3,4);
    return 0;
}