// Operator Overloading in Unary Operators;

#include <iostream>
using namespace std;

// class Count {
//     private:
//     int value;

//     public:

//     // Constructor to initialize count to 5
//     Count() : value(5) {}

//     // Overload ++ when used as prefix
//     void operator ++ () {
//         ++value += 100;
//     }

//     void display() {
//         cout << "Count: " << value << endl;
//     }
// };

// int main() {
//     Count count1;

//     // Call the "void operator ++ ()" function
//     ++count1;

//     count1.display();
//     return 0;
// }

// Overload ++ when used as prefix and postfix
// class Count
// {
// private:
//     int value;

// public:

// // Constructor to initialize count to 5
// Count() : value(5) {}

// // Overload ++ when used as prefix
// void operator ++ () {
//     ++value;
// }

// // Overload ++ when used as postfix
// void operator ++ (int)  {
//     value++;
// }

// void display() {
//     cout << "Count: " << value << endl;
// }
// };

// int main() {
//     Count count1;

//     // Call the "void operator ++ (int)" function
//     count1++;
//     count1.display();

//     // Call the "void operator ++ ()" function
//     ++count1;
//     count1.display();
//     return 0;
// }

// class Count
// {
// private:
//     int value;

// public:

// // Constructor to initialize count to 5
// Count() : value(5) {}

// // Overload ++ when used as prefix
// Count operator ++ () {
//     Count temp;

//     // Here, value is the value attribute of the calling object;
//     temp.value = ++value;

//     return temp;
// }

// // Overload ++ when used as postfix
// Count operator ++ (int) {
//     Count temp;

//     //Here, value is the value attribute of the calling object
//     temp.value = value++;

//     return temp;
// }

// void display() {
//     cout << "Count: " << value << endl;
// }
// };

// int main() {
//     Count count1, result;

//     // Call the "Count operator ++ ()" function
//     result = ++count1;
//     result.display();

//     // Call the "Count operator ++ (int)" function
//     result = count1++;
//     result.display();

//     return 0;
// }

// Operator Overloading in Binary Operators
// C++ program to overload the binary operator +
// This program adds two complex numbers

class Complex
{
private:
    float real;
    float imag;

public:
    // Constructor to initialize real and imag to 0
    Complex() : real(0), imag(0) {}

    void input()
    {
        cout << "Enter real and imaginary parts respectively: ";
        cin >> real;
        cin >> imag;
    }

    // Overload the + operator
    Complex operator+(const Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void
    output()
    {
        if (imag < 0)
            cout << "Output Complex number: " << real << imag << "i";
        else
            cout << "Output Complex number: " << real << "+" << imag << "i";
    }
};

int main() {
    Complex complex1, complex2, result;

    cout << "Enter first complex number:\n";
    complex1.input();

    cout << "Enter second complex number:\n";
    complex2.input();

    // complex1 calls the operator function
    // complex2 is passed as an argument to the function
    result = complex1 + complex2;
    result.output();

    return 0;
}
