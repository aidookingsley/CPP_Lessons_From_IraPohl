#include <iostream>
using namespace std;

// declare function to display marks
//  take a 1d array as parameter
// void display(int m[5])
// {
//     cout << "Displaying marks: " << endl;

//     // display array elements
//     for (int i = 0; i < 5; ++i)
//     {
//         cout << "Student " << i + 1 << ": " << m[i] << endl;
//     }
// }

// int main()
// {
//     // declare and initialize an array
//     int marks[5] = {88, 76, 90, 61, 69};

//     // call display function
//     // pass array as argument
//     display(marks);

// C++ Program to display the elements of two
// dimensional array by passing it to a function

// define a function
// pass a 2d array as a parameter
void display(int n[][2])
{
    cout << "Displaying Values: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << "num[" << i << "][" << j << "]: " << n[i][j] << endl;
        }
    }
}

int main()
{
    // initialize 2d array
    int num[3][2] = {
        {3, 4},
        {9, 5},
        {7, 1}};

    // call the function
    // pass a 2d array as an argument
    display(num);

    return 0;
}