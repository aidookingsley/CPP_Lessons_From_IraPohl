// Ira Pohl  Numerical Algorithms Module
// C++ For C Programmers Part B
// April 2016
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main(){
    double v1[3] = {1.0, 2.5, 4.6},
           v2[3] = {1.0, 2.0, -3.5};

    double sum, inner_p;

    // v1 and v2 are base addresses - so they can be used as
    // the beginning of an iterator range
    // v1 + 3 is pointer arithmetic and is the end sentinel.

    sum = accumulate(v1, v1 + 3, 0.0);
    inner_p = inner_product(v1, v1 + 3, v2, 0.0);

    std::cout << "Sum of v1 v2: " << sum << std::endl;
    std::cout << "Product of v1 v2" << inner_p << std::endl;

    /*
    For example, if we have a vector of integers, we can use the accumulate function to find the sum of all elements in the vector like so:
    */
    std::vector<int> v = {1, 2, 3, 4, 5};
    int new_sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout <<"New Sum: " <<new_sum << std::endl;

    /*
    For example, you can use std::inner_product to find the dot product of two vectors by passing the two vectors as input ranges and using the std::multiplies function as the binary function.
    */

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    int dot_product = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, std::plus<int>(), std::multiplies<int>());
    std::cout << "Dotproduct: "<<dot_product << std::endl;
}