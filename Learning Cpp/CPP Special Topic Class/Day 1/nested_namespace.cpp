#include <bits/stdc++.h>
using namespace std;

namespace outer {
    void hi(){ cout << "This is Outer function!" << '\n'; }
    namespace inner {
        void hi(){ cout << "This is inner function!" << '\n'; }
    }
}

int main()
{
    outer::hi();
    outer::inner::hi();
    return 0;
}