// Example 1: C++ Default Constructor

// C++ program to demonstrate the use of default constructor

#include <iostream>
using namespace std;

// declare a class
// class Wall
// {
// private:
//     double length;

// public:
//     // default constructor to initialize variable
//     Wall()
//     {
//         length = 5.5;
//         cout << "Creating a wall." << endl;
//         cout << "Length = " << length << endl;
//     }
// };

// int main() {
//     Wall wall1;
//     return 0;
// }

// Example 2: C++ Parameterized Constructor
// declare a class
// class Wall
// {
// private:
//     double length;
//     double height;

// public:
//     // parameterized constructor to initialize variables
//     Wall(double len, double hgt)
//     {
//         length = len;
//         height = hgt;
//     }

//     double calculateArea()
//     {
//         return length * height;
//     }
// };

// int main()
// {
//     // create object and initialize data members
//     Wall wall1(10.5, 8.6);
//     Wall wall2(8.5, 6.3);

//     cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
//     cout << "Area of Wall 2: " << wall2.calculateArea();

//     return 0;
// }

// Example 3: C++ Copy Constructor;
// declare a class
class Wall
{
private:
    double length;
    double height;

public:
    // initialize variables with parameterized constructor
    Wall(double len, double hgt)
    {
        length = len;
        height = hgt;
    }

    // copy constructor with a Wall object as parameter
    // copies data of the obj parameter
    Wall(Wall &obj) {
      length = obj.length;
      height = obj.height;
    }

    double calculateArea()
    {
        return length * height;
    }
};

int main()
{
    // create an object of Wall class
    Wall wall1(10.5, 8.6);

    // copy contents of wall1 to wall2
    Wall wall2 = wall1;

    // print areas of wall1 and wall2
    cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
    cout << "Area of Wall 2: " << wall2.calculateArea();

    return 0;
}