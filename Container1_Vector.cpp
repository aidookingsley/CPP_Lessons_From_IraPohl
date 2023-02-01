#include <vector>
#include <iostream>

int main()
{
    std::vector<double> numbers; //was originally int
    for (double i = 1.10; i <= 10.10; i++)
    {
        numbers.push_back(i); // add elements to the end of the vector
    }
    for (auto i : numbers)
    {
        std::cout << i << " "; // output all elements of the vector
    }
    return 0;
}
/*
VECTOR METHODS
v.size() -> get current size;
v.resize(int size)  -> resize the vector;

Constructors
vector<T> v;  empty sequence
vector<T> v(n); size n with default constructor T() called for each element
vector<T> v(n, value); value is of type T
- or convertible to T and is value of each element
*/
