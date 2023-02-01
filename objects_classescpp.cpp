//Example 1 : Object and Class in C++ Programming

#include <iostream>
using namespace std;

// create a class
// class Room {
//     public:
//         double length;
//         double breadth;
//         double height;

//         double calculateArea() {
//             return length * breadth;
//         }

//         double calculateVolume() {
//             return length * breadth * height;
//         }
// };

// int main() {
//     //create object of Room class
//     Room room1;

//     // assign values to data members
//     room1.length = 42.5;
//     room1.breadth = 30.8;
//     room1.height = 19.2;

//     Room room2 = room1;

//     // calculate and display the area and volume of the room
//     cout << "Area of Room =  " << room1.calculateArea() << endl;
//     cout << "Volume of Room =  " << room2.calculateVolume() << endl;

//     return 0;
// }

// Example 2: Using public and private in C++ Class

class Room {
    private:
        double length;
        double breadth;
        double height;

        public:

        //function to initialize private variables
        void initData(double len, double brth, double hgt) {
            length = len;
            breadth = brth;
            height = hgt;
        }

        double calculateArea() {
            return length * breadth;
        }

        double calculateVolume() {
            return length * breadth * height;
        }
};

int main() {

    // create object of Room class
    Room room1, room2, room3;

    // pass the values of private variables as arguments
    room1.initData(42.5, 30.8, 19.2);
    room2.initData(45.5, 31.8, 17.2);
    room3.initData(56.1, 29.5, 24.2);

    cout << "Area of Room1 = " << room1.calculateArea() << endl;
    cout << "Volume of Room1 =  " << room1.calculateVolume() << endl;

    cout << "Area of Room2 = " << room2.calculateArea() << endl;
    cout << "Volume of Room2 =  " << room2.calculateVolume() << endl;

    cout << "Area of Room3 = " << room3.calculateArea() << endl;
    cout << "Volume of Room3 =  " << room3.calculateVolume() << endl;

    return 0;
}