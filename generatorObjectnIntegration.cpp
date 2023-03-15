#include <iostream>

class FibonacciIterator
{
public:
    FibonacciIterator() : a(0), b(1) {}

    int operator*() const
    {
        return b;
    }

    FibonacciIterator &operator++()
    {
        int temp = a + b;
        a = b;
        b = temp;
        return *this;
    }

    bool operator!=(const FibonacciIterator &other) const
    {
        return b != other.b;
    }

private:
    int a, b;
};

void fibonacci(int n)
{
    FibonacciIterator begin, end;

    for (FibonacciIterator it = begin; it != end && n > 0; ++it, --n)
    {
        std::cout << *it << " ";
    }
}

int main()
{
    fibonacci(10);
    return 0;
}
