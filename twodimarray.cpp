#include <iostream>
using namespace std;

int main()
{
    // int test[3][4] = {
    //     {2, -5},
    //     {4, 0},
    //     {9, 1}};

    // // use of nested for loop
    // // access rows of the array
    // for (int i = 0; i < 3; ++i) {

    //     // access columns of the array
    //     for (int j = 0; j < 2; ++j) {
    //         cout << "test[" << i << "][" << j << "] = " << test[i][j] << endl;
    //     }
    // }

    // int numbers[2][3];

    // cout << "Enter 6 numbers: " << endl;

    // // Storing user input in the array
    // for (int i = 0; i < 2; ++i)
    // {
    //     for (int j = 0; j < 3; ++j)
    //     {
    //         cin >> numbers[i][j];
    //     }
    // }

    // cout << "The numbers are: " << endl;

    // // Printing array elements
    // for (int i = 0; i < 2; ++i)
    // {
    //     for (int j = 0; j < 3; ++j)
    //     {
    //         cout << "numberes[" << i << "][" << j << "]: " << numbers[i][j] << endl;
    //     }
    // }

    // This array can store upto 12 elements (2x3x2)
    // int test[2][3][2] = {
    //     {{1, 2}, {3, 4}, {5, 6}},
    //     {{7, 8}, {9, 10}, {11, 12}}};
    // // Displaying the values with proper index.
    // for (int i = 0; i < 2; ++i)
    // {
    //     for (int j = 0; j < 3; ++j)
    //     {
    //         for (int k = 0; k < 2; ++k)
    //         {
    //             cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << endl;
    //         }
    //     }
    // }

    int numbers[4][3][3];

    cout << "Enter 36 numbers: " << endl;

    // Storing user input in the array
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                cin >> numbers[i][j][k];
            }
        }
    }
    cout << "The numbers are: " << endl;

    // Displaying the values with proper index.
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                cout << "numbers[" << i << "][" << j << "][" << k << "] = " << numbers[i][j][k] << endl;
            }
        }
    }
    return 0;
}