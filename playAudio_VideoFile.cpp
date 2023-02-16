#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace fs = boost::filesystem;

void play_video(const fs::path &filepath)
{
    std::string command = "open " + filepath.string();
    std::system(command.c_str());
}

int main()
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    fs::path filepath(filename);
    play_video(filepath);
    return 0;
}