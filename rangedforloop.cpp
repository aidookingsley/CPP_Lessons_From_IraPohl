#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // initialize array
    // int numArray[] = {1, 2, 3, 4, 5};

    // use of ranged  for loop to print array elements
    // for (int n : numArray)
    {
        // cout << n << " ";
    }

    // declare  and initialize vector
    // vector<int> num_vector = {1, 2, 3, 4, 5};

    // // print vector elements
    // for (int n : num_vector) {
    //     cout << n << " ";
    // }

    // define the collection in the loop itself
    for (int n : {1, 2, 3, 4, 5})
    {
        cout << n << " ";
    }

    return 0;
}