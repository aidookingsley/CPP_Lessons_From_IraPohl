#include <deque>
#include <iostream>

int main()
{
    std::deque<int> numbers;
    numbers.push_back(10);
    numbers.push_front(5); // add elements to the front and back of the deque
    numbers.push_back(15);
    for (auto i : numbers)
    {
        std::cout << i << " "; // output all elements of the deque
    }
    return 0;
}
