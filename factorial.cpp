// Recursive factorial function
#include <iostream>
using namespace std;
long factorial(int n)
{
    // n = (n <= 1) ? 1 : n * factorial(n - 1);

    // if (n <= 1)
    //     return 1;
    // else
    //     return n * factorial(n - 1);

    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
};

int main()
{
    int n;
    cout << "Input a value: ";
    cin >> n;
    cout << "Factorial of " << n << " is : " << factorial(n) << endl;
}