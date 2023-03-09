#include <iostream>
#include <fstream>
#include <numeric>
using namespace std;

int main()
{
    ifstream myin("../../Desktop/enq.txt");
    istream_iterator<int> in(myin);
    istream_iterator<int> eos;
    cout << "Sum of data is " << accumulate(in, eos, 0) << endl;
}

/*replace algorithm
template<class ForwardIterator, class T>
void replace(ForwardIterator first, ForwardIterator last, const T&x, const T&y);

this algorithm replaces occurences of x by y in the specified iterator range.

*/