#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, std::string, double> myTuple(1, "hello", 3.14);
    std::cout << std::get<0>(myTuple) << std::endl; // prints "1"
    std::cout << std::get<1>(myTuple) << std::endl; // prints "hello"
    std::cout << std::get<2>(myTuple) << std::endl; // prints "3.14"
    return 0;
}
