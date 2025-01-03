#include <iostream>
#include "Stacks.h"
using namespace std;

ostream &operator <<(ostream &out, Stack &s) {
    for (int i = 0; i < s.getTopValue(); i++)
    {
        out << s.get(i) << " ";
    }
    return out;
}

int main() {
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    
    cout << s << endl;
    s.pop();
    cout << s << endl;
    s.pop();
    cout << s << endl;
    s.pop();
    cout << s << endl;
    s.pop();
    cout << s << endl;
    return 0;
}