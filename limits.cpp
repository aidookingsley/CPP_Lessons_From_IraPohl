#include <iostream>
using namespace std;

int main()
{
    cout << numeric_limits<int>::max()
         << " is the maximum int.\n";
    cout << numeric_limits<float>::max()
         << " is the maximum float.\n";
    cout << numeric_limits<double>::max()
         << " is the maximum double.\n";
    cout << numeric_limits<long long int>::max()
         << " is the maximum long long int.\n";
    cout << numeric_limits<unsigned int>::max()
         << " is the maximum unsigned int.\n";
    cout << "all colors sum up to  " << 256 * 256 * 256 << endl;

    
    return 0;
}