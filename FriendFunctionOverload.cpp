// We will use friend function to add two complex numbers
// to see the difference in implementation
#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // friend function to overload binary + to add two complex numbers
    friend Complex operator+(Complex const &, Complex const &);

    void print()
    {
        cout << real << " + i" << imag << endl;
    }
};

Complex operator+(Complex const &c1, Complex const &c2)
{
    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}

int main()
{
    Complex c1(2, 5), c2(3, 7);
    cout << "c1 = ";
    c1.print();
    cout << "c2 = ";
    c2.print();
    cout << "c3 = c1 + c2 = ";
    Complex c3 = c1 + c2; // calls overloaded + operator

    c3.print();
}