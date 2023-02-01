#include <iostream>
#include <complex>
using namespace std;

template <class T> // T is a generic type
T sum(const T data[], int size, T s = 1)
{
    for (int i = 0; i < size; ++i)
        s *= data[i];
    return s;
};

// Signature matching algorithm with the use of Templates in c++

int main()
{
    cout << "Template for sum()" << endl;
    int a[] = {1, 2, 3};
    double b[] = {2.1, 2.2, 2.3};
    cout << sum(a, 3) << endl;
    cout << sum(b, 3) << endl;
    for (int i = 0; i < 3; ++i)
        cout << a[i] << endl;
    for (int i = 0; i < 3; ++i)
        cout << b[i] << endl;
}