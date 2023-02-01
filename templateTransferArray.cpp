#include <iostream>
using namespace std;

// Template generic assignement function

template <class T>
int transfer(T *from, T *to, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int i = 0; i < size; ++i)
            to[i] = from[i];
        return size;
    }
}

int main()
{
    int a[10], b[10];
    double c[20], d[20];
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; ++i)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;

    transfer(a, b, 10);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    for (auto i : b)
        cout << i << " ";
    cout << endl;

    cout << "Enter 20 fractional numbers: ";
    for (auto i : c)
    {
        cin >> i;
        cout << i << " ";
    }
    cout << endl;
    transfer(c, d, 20);
    for (auto i : c)
        cout << i << "\t";
    for (auto i : d)
        cout << i << " ";

    // 21 32 43 34 21 22 23 10 11 22
    // 10.5 12.3 11.2 14.6 56.7 44.6 34.1 45.7 34.8 22.9 13.2 12.5 23.4 43.2 15.6 17.9 18.0 12.3 12.0 11.0
}