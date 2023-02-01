#include <unordered_set>
#include <iostream>

int main()
{
    // Create an unordered set of strings
    std::unordered_set<std::string> mySet;

    // Insert some elements into the set
    mySet.insert("apple");
    mySet.insert("banana");
    mySet.insert("orange");
    mySet.insert("mango");

    // Print out the set elements
    for (auto element : mySet)
        std::cout << element << " ";
    std::cout << std::endl;
    // Output may be different on each run, but all elements are present
}
