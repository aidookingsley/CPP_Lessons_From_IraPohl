#include <algorithm>
#include <vector>
#include <iostream>

void incr(int &i)
{
    static int n = 1;
    i = n++;
}
void outvec(int i) { std::cout << i << std::endl; }

int main()
{
    std::vector<int> v(6);
    // for_each(v.begin(), v.end(), incr);
    // for_each(v.begin(), v.end(), outvec);

    // New foreach with lambda expression
    for_each(v.begin(), v.end(), [](int &i)
             {static int n = 1; i = n++; });
    for_each(v.begin(), v.end(), [](int i)
             { std::cout << i << std::endl; });
}