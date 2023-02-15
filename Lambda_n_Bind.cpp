#include <iostream>
#include <vector>

enum class BattleCondition
{
    red,
    yellow,
    green
};

void print_it(const int &n)
{
    std::cout << "-" << n;
}

int main()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    // std::bind
    std::for_each(nums.begin(), nums.end(), std::bind(&print_it, std::placeholders::_1));
    std::cout << std::endl;
    // lambda inline expression
    std::for_each(nums.begin(), nums.end(), [](const int &n)
                  { std::cout << "-" << n; });
    std::cout << std::endl;

    // lambda assignment-> lambda doesn't have a name, it is just being assigned to a variable bcos lambdas are 1st class objects in C++
    auto myLambda = [](const int &n)
    { std::cout << "*" << n; };
    std::for_each(nums.begin(), nums.end(), myLambda);
    std::cout << std::endl;

    // here lambda is converting a switch statement into a switch expression. so it itakes the switch statement and wraps it in a lambda. the [&] is for reference scoping so we can get access to currentLight and use it to set our shieldLevel
    auto currentLight = BattleCondition::green;
    const auto shieldLevel = [&]()
    {
        switch (currentLight)
        {
        case BattleCondition::green:
            return 50;
        case BattleCondition::yellow:
            return 700;
        case BattleCondition::red:
            return 1000;
        }
    }();
    std::cout << "Current Shield level = " << shieldLevel << std::endl;
    return 0;
}