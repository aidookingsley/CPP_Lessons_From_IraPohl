// Overloading of the binary operator using the member operator function.
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

    // Operator function to overload binary + to add two complex numbers
    Complex operator+(Complex const &obj)
    {
        Complex c3;
        c3.real = real + obj.real;
        c3.imag = imag + obj.imag;
        return c3;
    }

    void print()
    {
        cout << real << " + i" << imag << endl;
    }
};

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
