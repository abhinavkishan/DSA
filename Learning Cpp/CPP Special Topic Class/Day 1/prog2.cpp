#include <bits/stdc++.h>
using namespace std;

void size_func(int *arr) {
    // returning size of pointer
    cout << "size: " << sizeof(arr);
}

int main()
{
    int arr[] = {1,2,3,4};
    size_func(arr);
    return 0;
}