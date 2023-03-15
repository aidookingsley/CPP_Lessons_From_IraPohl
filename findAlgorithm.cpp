#include <iostream>
#include <algorithm>

int main()
{
    std::string words[5] = {"my", "hop", "mop", "hope", "cope"};

    std::string *where;
    where = find(words, words + 5, "hop");
    std::cout << *++where << std::endl;
    std::sort(words, words + 5);
    where = find(words, words + 5, "hop");
    std::cout << *++where << std::endl;
}