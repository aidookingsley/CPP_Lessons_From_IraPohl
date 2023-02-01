#include <list>
#include <iostream>

int main()
{
    std::list<int> numbers;
    numbers.push_back(10); 
    numbers.push_front(5); // add elements to the front of the list
    numbers.insert(++numbers.begin(), 7); // insert an element in the middle of the list
    for (auto i : numbers)
    {
        std::cout << i << " "; // output all elements of the list
    }
    return 0;
}
