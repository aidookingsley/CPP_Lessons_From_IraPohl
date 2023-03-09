#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

template <typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last)
{
    for (; first != last; first++)
        *first = (*first) * (*first); // dereference the element n multiply toget a square
}

int main()
{
    vector<int> w = {3, 4, 7};
    square(w.begin(), w.end());
    for (auto i : w)
        cout << i << "\t";
    cout << endl;
}