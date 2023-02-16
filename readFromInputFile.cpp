#include <iostream>
#include <string>
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
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    fs::path filepath(filename);
    read_file(filepath);
    return 0;
}

/*
Here's an example of how to modify the code to use this path format to read a file from the desktop: //or any other specified location
int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    fs::path filepath("/Users/<username>/Desktop/" + filename);
    read_file(filepath);
    return 0;
}
*/