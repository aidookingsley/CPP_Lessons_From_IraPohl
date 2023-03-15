#include <functional>
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    auto add5 = std::bind(add, std::placeholders::_1, 5);
    int x = 10;
    int y = add5(x);
    std::cout << "Result: " << y << std::endl;
    return 0;
}