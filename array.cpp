#include <iostream>
using namespace std;

int main()
{
    // int numbers[5] = {7, 5, 6, 12, 35};

    // cout << "The numbers are: ";

    // //Printing array elements
    // // using range based for loop
    // for (const int &n : numbers) {
    //     cout << n << " ";
    // }

    // cout << "\nThe numbers are: ";

    // // Printing array elements
    // // using traditional for loop
    // for (int i = 0; i < 5; ++i) {
    //     cout << numbers[i] << " ";
    // }

    // int numbers[5];

    // cout << "Enter 5 numbers: " << endl;
    // // store input from user to array
    // for (int i = 0; i < 5; ++i)
    // {
    //     cin >> numbers[i];
    // }

    // cout << "The numbers are: ";

    // // print array elements
    // for (int n = 0; n < 5; ++n)
    // {
    //     cout << numbers[n] << " ";
    // }

    // Display Sum and Average of Array Elements Using for Loop

    // initialize an array without specifying size
    double numbers[] = {7, 5, 6, 12, 35, 27};

    double sum = 0;
    double count = 0;
    double average;

    cout << "The numbers are: ";

    // print array elements
    // use of range-based for loop
    for (const double &n : numbers)
    {
        cout << n << " ";

        // calculate the sum
        sum += n;

        // count the no. of array elements
        ++count;
    }

    // print the sum
    cout << "\nTheir Sum = " << sum << endl;

    // find the average
    average = sum / count;
    cout << "Their Average = " << average << endl;

    return 0;
}