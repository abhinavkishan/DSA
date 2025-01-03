#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name = "Batman";
    stringstream ss;
    ss << "Time to complete: " << 10 << endl;
    ss << "Name: " << name << endl;
    ss << "Level: " << 'A' << endl;
    ss << "Health: " << 100 << endl;
    cout << ss.str();
    return 0;
}