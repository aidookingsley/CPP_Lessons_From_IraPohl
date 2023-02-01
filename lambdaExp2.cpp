#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> squared;
    std::vector<int> cubed;

    // lambda function that takes an integer parameter and returns a square
    std::transform(original.begin(), original.end(), std::back_inserter(squared), [](int x)
                   { return x * x; });

    // lambda function that takes aninteger parameter and returns a cube
    std::transform(original.begin(), original.end(), std::back_inserter(cubed), [](int x)
                   { return x * x * x; });

    // lambda function that returns the first element in both the original and squared vector
    auto first_num = std::find_if(original.begin(), original.end(), [](int i)
    { return i; });

    std::cout<< "Original: ";
    for (auto i : original)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Squared: ";
    for (auto i : squared)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "First element in original: " << *first_num<< 
    std::endl;
    std::cout << "Last element in original: " << original.back() << std::endl;
    std::cout << "Last element in cubed: " << cubed[cubed.size() -1] << std::endl;
    std::cout << "5th element in cubed:  " << cubed.at(4) << std::endl;
    std::cout << "Cubed: ";
    for (auto i : cubed){
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "6th element in cubed: " << cubed[6] << std::endl;
    std::cout << "10th element in squared: " << squared.at(9) << std::endl;
    return 0;
}