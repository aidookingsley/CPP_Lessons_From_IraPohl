#include <iostream>
#include <iterator>
#include <algorithm>

template <class ForwIter>
void print(ForwIter first, ForwIter last, const char *title)
{
    std::cout << title << std::endl;
    for (auto it = first; it != last; ++it)
        std::cout << *it << '\t';
    std::cout << std::endl;
}

int main()
{
    int data[3] = {9, 10, 11};

    print(std::begin(data), std::end(data), "Original values");
    std::transform(std::begin(data), std::end(data), std::begin(data), [](int x)
                   { return x * 2; });

    print(std::begin(data), std::end(data), "New values");
    return 0;
}