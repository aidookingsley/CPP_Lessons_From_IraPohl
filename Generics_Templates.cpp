#include <iostream>
#include <complex>
using namespace std;

// template<typename T>
template <class T>
inline void Swap(T &d, T &s)
{
    T temp = d;
    d = s;
    s = temp;
};

int main()
{
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;
    complex<double> r(2.4, 3.5), s(3.4, 6.7);
    cout << "inputs: " << m << " , " << n << endl;
    Swap(m, n);
    cout << "output: " << m << " , " << n << endl;

    cout << "double inputs: " << x << " , " << y << endl;
    Swap(x, y);
    cout << "double output: " << x << " , " << y << endl;

    cout << "complex inputs: " << r << " , " << s << endl;
    Swap(r, s);
    cout << "complex outputs: " << r << " , " << s << endl;
}