#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Using a lambda function to find the first even number in the vector
    auto even_num = std::find_if(v.begin(), v.end(), [](int i)
                                 { return i % 2 == 0; });
    std::cout << "First even number: " << *even_num
              << std::endl;

    // Using a lambda function to count the number of odd numbers in the vector
    int odd_count = std::count_if(v.begin(), v.end(), [](int i)
                                  { return i % 2 != 0; });
    std::cout << "Number of odd numbers: " << odd_count << std::endl;

    // Using a lambda function to add 10 to every element in the vector
    std::for_each(v.begin(), v.end(), [](int &i)
                  { i += 10; });
    std::cout << "Vector after adding 10: ";
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Using a lambda function to sort the vector in descending order
    std::sort(v.begin(), v.end(), [](int i, int j)
              { return i > j; });

    std::cout << "Vector after modifications: ";
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}