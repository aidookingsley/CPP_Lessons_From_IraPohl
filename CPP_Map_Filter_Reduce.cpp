#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
    // Mapping example
    std::vector<int> v{1, 2, 3, 4};
    std::vector<int> mapped_v;
    std::transform(v.begin(), v.end(), std::back_inserter(mapped_v), [](int x)
                   { return x * 2; });
    std::cout << "Mapped vector: ";
    for (int x : mapped_v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Filtering example
    std::vector<int> filtered_v;
    std::copy_if(v.begin(), v.end(), std::back_inserter(filtered_v), [](int x)
                 { return x % 2 == 0; });
    std::cout << "Filtered vector: ";
    for (int x : filtered_v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Reducing example
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
