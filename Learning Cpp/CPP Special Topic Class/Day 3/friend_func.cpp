#include <bits/stdc++.h>
using namespace std;

class Box {
    private:
        int length;
        // friend int printLength(Box); // works same as friend int printLength(Box b) in public

    public:
        friend int printLength(Box); // friend function        
        Box(): length(0) {}
};

int printLength(Box b) {
    b.length += 10;
    return b.length;
}

int main()
{
    Box b;
    cout << "Length of box: " << printLength(b) << endl;
    // cout << "Length of box: " << b.printLength(b) << endl;   -> error: ‘class Box’ has no member named ‘printLength’
    return 0;
}