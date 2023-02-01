#include <iostream>
using namespace std;

int main()

{
    char c = 'A';
    int i = 3, j = 1, m = 0;
    bool p = false, q = true;

    cout << c << " is integer value " << int(c) << " and ! 'A' is" << !c << endl;
    cout << "i = " << i << ", !i = " << !i << endl;
    cout << "!!i = " << !!i << ", !m = " << !m
         << endl;
    cout << "p = " << p << ", q = " << q << endl;
    cout << "!p = " << !p << ", !q = " << !q
         << endl;
    cout << "!(i + j) || m = " << (!(i + j) || m)
         << endl;
    cout << "q || (j / m) = " << (q || (j / m)) << endl;
    cout << "(j / m) || q = " << ((j / m) || q) << endl;
}