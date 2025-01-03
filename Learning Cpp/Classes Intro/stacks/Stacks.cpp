// Implemnentaion of Stacks.h
#include <iostream>
#include "Stacks.h"
Stack::Stack(): topValue(-1), data(new char[100]) {};
Stack::~Stack() { delete [] data; };
void Stack::push(char c) { data[++topValue] = c; };
void Stack::pop() { topValue--; };
int Stack::isEmpty() { return topValue == -1; };
char Stack::top() { return data[topValue]; };
int Stack::getTopValue() { return topValue; };
char Stack::get(int i) { return data[i]; };
// ostream& Stack::operator <<(ostream& out, Stack& s) {
//     for (int i = 0; i <= topValue; i++)
//         out << s.get(i) << " ";
//     return out;
// }
// ostream &operator <<(ostream &out, Stack &s) {
//     for (int i = 0; i <= s.topValue; i++)
//         out << s.get(i) << " ";
//     return out;
// }