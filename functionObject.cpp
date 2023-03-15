#include <iostream>
#include <functional>
#include <numeric>
int main()
{
    double v1[3] = {1.0, 2.5, 4.6}, sum;
    sum = std::accumulate(v1, v1 + 3, 0.0, std::minus<int>());
    std::cout << "sum = " << sum << std::endl;
}
