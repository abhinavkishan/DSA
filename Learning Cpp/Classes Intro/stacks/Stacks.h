// Interface
// #include <iostream>
class Stack {
    private:
        int topValue; char *data;
    public:
        Stack();
        ~Stack();
        void push(char);
        void pop();
        int isEmpty();
        char top();
        char get(int);
        int getTopValue();
        // ostream& operator <<(ostream&, Stack&);
};
