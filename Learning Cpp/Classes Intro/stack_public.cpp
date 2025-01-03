#include <iostream>
#include <vector>
using namespace std;

class Stack_arr {
    public: char *data; int top;
    public:
        int empty() { return (top == -1); }
        void push(char x) { data[++top] = x; }
        void pop() { top--; }
        char top_value() { return data[top]; }
};

class Stack_vector {
    public: vector<char> data; int top;
    public:
        int empty() {return (top == -1); }
        void push(char x) { data[++top] = x; }
        void pop() { top--; }
        char top_value() { return data[top]; }
};

int main() {
    Stack_arr s1;
    Stack_vector s2;

    // exposed implementation
    s1.data = new char[100];
    s2.data.resize(100);
    s1.top = s2.top = -1;
    char str[] = "DATA";

    for(int i=0; str[i]; i++) {
        s1.push(str[i]);
        s2.push(str[i]);
    }

    s2.top = s1.top = 2; // risky

    while(!s1.empty()) {
        cout << s1.top_value() << " ";
        s1.pop();
    }
    cout << endl;

    while(!s2.empty()) {
        cout << s2.top_value() << " ";
        s2.pop();
    }
    cout << endl;

    // vector destructor will be called automatically
    delete [] s1.data;
    return 0;
}