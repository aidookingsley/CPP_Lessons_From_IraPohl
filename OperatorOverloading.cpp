// Overloading of the unary operator using member operator function.

#include<iostream>
using namespace std;

class Distance {
    public:
        int feet;

    // Constructor to initialize the object's value
    Distance(int feet) {
        this->feet = feet;
    }

    // Operator function to overload ++operator to perform increment on Distance obj
    void operator++() {
        feet++;
    }

    void print() {
        cout << "\nIncremented Feet value: " << feet;
    }
};

int main() {
    Distance d1(9);
    // Use (++) unary operator
    ++d1;
    d1.print();

    return 0;
}