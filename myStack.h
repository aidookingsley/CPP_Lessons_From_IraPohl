#ifndef MYSTACK_H
#define MYSTACK_H

#include <vector>

template <class T>
class myStack
{
public:
    // constructor
    explicit myStack(int size = 100) : max_len(size), s(new T[size])
    {
        assert(s != 0);
    }
    // destructor
    ~myStack() { delete[] s; }
    // reset the stack
    void reset() {}
    // push an element on top of the stack
    void push(const T &c) {}
    // pop an element from the top of the stack
    T pop() { return *s; }
    // get the element on top of the stack
    T top() const
    {
        return s;
    }
    // check if the stack is empty
    bool empty() const { return EMPTY; }
    // check if the stack is full
    bool full() const { return max_len - 1; }
    enum
    {
        EMPTY = -1
    };
    T *s;
    int max_len;
    // int top;
};

#endif
