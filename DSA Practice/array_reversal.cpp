#include <iostream>
using namespace std;

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};
    int n = sizeof(data) / sizeof(data[0]);
    int start = 0, end = n - 1;
    while(start < end) {
        swap(data[start], data[end]);
        start++;
        end--;
    }
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
}