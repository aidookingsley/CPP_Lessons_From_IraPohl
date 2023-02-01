#include <iostream>
#include <string>
#include <algorithm>

template <class T>
void reverseString(T &str) {
    std::reverse(str.begin(), str.end());
}

int main() {
    std::string myString = "Hello, World!";
    std::cout << "Original string: " << myString << std::endl;

    reverseString(myString);
    std::cout << "Reversed string: " << myString << std::endl;

    return 0;
}
