#include <bits/stdc++.h>
using namespace std;

class MyArray {
    int *data;
    int size;
    public:
    MyArray(int size=0):size(size) {
        data = new int[size];
        for(int i = 1; i <= size; i++) {
            data[i-1] = i;
        }
    }
    int operator[](int index) {
        if(index < 0 || index >= size) throw "Out of range1";
        return data[index];
    }
};

int main() {
    MyArray a(5);
    cout << a[5];
}