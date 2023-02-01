#include <map>
#include <iostream>

int main()
{
    // Create a map of strings to integers
    std::map<std::string, int> myMap;

    // Insert some elements into the map
    myMap["apple"] = 3;
    myMap["banana"] = 2;
    myMap["orange"] = 4;
    myMap["mango"] = 1;

    // Print out the map elements
    for (auto element : myMap)
        std::cout << element.first << " " << element.second << std::endl;
    // Output:
    // apple 3
    // banana 2
    // mango 1
    // orange 4
}
