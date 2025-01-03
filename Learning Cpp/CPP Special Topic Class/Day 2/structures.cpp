#include <bits/stdc++.h>
using namespace std;

// #pragma pack(1)

struct test {
    char c2;
    short i1;
    char c1;
};

struct Rectangle {
    int width, height;
    Rectangle(int w, int h): width{w}, height{h} {}
    // for calculating size method is just a pointer
    void area_of_rectangle(){
        cout << width << height << endl;
    }
    ~Rectangle() { cout << "Destructor called" << '\n';}
};

int main()
{
    Rectangle rec(2,9);
    auto recptr = new Rectangle(6,9);
    delete recptr;
    // cout << sizeof(test);  
    return 0;
}