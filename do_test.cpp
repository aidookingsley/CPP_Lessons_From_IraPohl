#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int sum = 0, n;

    cout << "\nYou must enter 10 positive integers";
    for (int i = 0; i < 10; ++i)
    {
        // loop until a positive integer is entered
        do
        {
            cout << "\nEnter a positive integer: ";
            cin >> n;
        } while (n <= 0);
        sum += n;
    }
    cout << "Sum of 10 positive numbers is " << sum << endl;
    cout << "The average  of the numbers is " << sum / 10 << endl;

    // int x;
    // cout << "Enter a value: ";
    // for (int i = 0; i < 10; ++i)
    // {
    //     cin >> x;
    //     if (x < 0.0)
    //     {
    //         cout << "All done" << endl;
    //         break;
    //     }
    //     cout << sqrt(x) << endl;
    // }
    // char c;
    // cout << "Enter a value: ";
    // for (int i = 0; i < 10; ++i)
    // {
    //     cin.get(c);
    //     if (isdigit(c))
    //     {
    //         cout << c;
    //         continue;
    //     }
    //     c++;
    // }
}