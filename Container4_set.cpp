#include <set>
#include <iostream>

// set is a container that stores unique elements in ascending order

int main()
{
    // Create a set of integers
    std::set<int> mySet;

    // Insert some elements into the set
    mySet.insert(4);
    mySet.insert(2);
    mySet.insert(1);
    mySet.insert(3);

    // Print out the set elements
    for (auto element : mySet)
        std::cout << element << " ";
    std::cout << std::endl;
    // Output: 1 2 3 4
}
