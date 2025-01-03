#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    cout << "Enter your name: ";
    // cin >> name;
    // using getline() to read the whole line at once
    getline(cin, name);
    cout << "Hello " << name << "!" << endl;
    return 0;
}