#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace fs = boost::filesystem;

void read_file(const fs::path &filepath)
{
    fs::ifstream input(filepath);
    std::string line;
    while (std::getline(input, line))
    {
        std::cout << line << std::endl;
    }
}

int main()
{
    fs::path filepath = "homework2.txt";
    read_file(filepath);
    return 0;
}