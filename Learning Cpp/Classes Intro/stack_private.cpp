#include <bits/stdc++.h>
using namespace std;

class Stack_dynamic {
    private: char *data; int top; 
    public:
        Stack_dynamic(): data(new char[100]), top(-1) { }
        ~Stack_dynamic() { delete [] data; }
        void push(char c) { data[++top] = c; }
        char pop() { return data[top--]; }
        bool empty() { return top == -1; }
};

class Stack_vector {
    private: vector<char> data; int top;
    public:
        Stack_vector(): top(-1) { data.resize(100); }
        void push(char c) { data[++top] = c; }
        char pop() { return data[top--]; }
        bool empty() { return top == -1; }
};

int main() {
    Stack_dynamic s1;
    Stack_vector s2;
    s1.push('a');
    s2.push('a');
    s1.push('b');
    s2.push('b');
    s1.push('c');
    s2.push('c');
    while (!s1.empty()) {
        cout << s1.pop() << " ";
    }
    cout << endl;
    while (!s2.empty()) {
        cout << s2.pop() << " ";
    }
    cout << endl;
    return 0;
}