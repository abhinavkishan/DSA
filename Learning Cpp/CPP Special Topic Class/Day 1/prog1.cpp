#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 69;
    int set = 0;
    while(a >= 0) {
        if(a && 1) {
            set++;
        }
        a = a >> 1;
    }
    // printf("Number of bits set: %d\n",set);
    cout << set << endl;
    return 0;
}