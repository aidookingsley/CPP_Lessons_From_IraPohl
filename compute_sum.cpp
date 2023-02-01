#include <iostream>
using namespace std;

int compute_sum(int n)
{
    int sum = 0;
    for (; n > 0; --n)
        sum += n;
    return sum;
}

int main()
{
    int n = 3, sum;

    cout << n << endl;
    sum = compute_sum(n);
    cout << n << endl;
    cout << sum << endl;
}