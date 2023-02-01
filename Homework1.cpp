#include <iostream>
#include <vector>
using namespace std;
const int N = 40; // global to main() function
template <class summable>
inline void sum(summable &p, const vector<summable> &d)
{
    p = 0;
    for (auto i : d)
    {
        p += i;
    }
}

int main()
{
    vector<int> data(N);
    for (int i = 0; i < N; ++i)
    {
        data[i] = i;
    }
    int accum = 0;
    sum(accum, data);
    cout << "sum is " << accum << endl;
}
