#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 6, b = 9;
    cout << "a = " << a << ", b = " << b << '\n';
    swap_ref(a, b);
    cout << "a = " << a << ", b = " << b << '\n';
    return 0;
}