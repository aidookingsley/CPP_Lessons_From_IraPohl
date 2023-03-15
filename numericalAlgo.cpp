#include <iostream>
#include <numeric>
int main()
{
    double v1[3] = {1.0, 2.5, 4.6}, v2[3] = {1.0, 2.0, -3.5};
    double sum, inner_p;

    sum = std::accumulate(v1, v1 + 3, 0.0);
    inner_p = std::inner_product(v1, v1 + 3, v2, 0.0);
    std::cout << "sum = " << sum << ", product = " << inner_p << std::endl;
}