#include <iostream>
#include <stack>
#include <complex>
#include <cassert>
#include <vector>
#include "myStack.h"
using namespace std;

// Template stack implementation
template <class TYPE>
// class myStack
// {
// public:
//     explicit myStack(int size = 100) : max_len(size), top(EMPTY), s(new TYPE[size]) { assert(s != 0); }
//     ~myStack() { delete[] s; }
//     void reset() { top = EMPTY; }
//     void push(TYPE c) { s[++top] = c; }
//     TYPE pop() { return s[top--]; }
//     TYPE top(){return s[top]};
//     TYPE top_of() const { return s[top]; }
//     bool empty() const { return top == EMPTY; }
//     bool full() const { return top == max_len - 1; }
//     enum
//     {
//         EMPTY = -1
//     };
//     TYPE *s;
//     int max_len;
//     int top;
// };

// Reversing an array of char* represented strings
void reverse(char *str[], int n)
{
    myStack<char *> stk_str;
    int i;

    for (i = 0; i < n; ++i)
        stk_str.push(str[i]);
    for (i = 0; i < n; ++i)
        str[i] = stk_str.top();
    stk_str.pop();
}

// Initialize stack of complex numbers from an array

void init(complex<int> c[], myStack<complex<int>> &stk, int n)
{
    for (int i = 0; i < n; ++i)
        stk.push(c[i]);
}

// Reversing a string with a ch_stack
int main()
{
    typedef myStack<int> intStack;
    myStack<char *> strStack;
    intStack s, pop, top, push;
    myStack<char> stk_ch;
    std::vector<std::complex<int>> v;
    std::stack<std::complex<int>, std::vector<std::complex<int>>> stk_cmplx(v);
    complex<int> cplx;
    char str[100] = {"My name is Adekyensroma Oduahoma!"};
    int i = 0;

    cout << str << endl;
    s.reset();
    while (str[i] && !s.full())
        s.myStack<int>::push(str[++i]);
    while (!s.empty())
        cout << s.pop();
    cout << endl;
    cout << str << endl;
}