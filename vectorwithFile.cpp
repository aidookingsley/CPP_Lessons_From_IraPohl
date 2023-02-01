#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// int main()
// {
//     ifstream word_file("../../Desktop/enq.txt");
//     istream_iterator<string> start(word_file), end;
//     vector<string> words(start, end);
//     cout << " \n\nwords as read\n";
//     for (auto str : words)
//         cout << str << "\t";
//     sort(words.begin(), words.end());
//     cout << " \n\nwords as sorted\n";
//     for (auto str : words)
//         cout << str << "\t";
//     cout << endl;
// }

// an example of a C++ program that counts the number of words and the frequency of a word in a text file:

int main(){
    std::map<std::string, int> word_count;
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if(!file){
        std::cout << "Unable to open file." << std::endl;
        return 1;
    }

    int wordCount = 0;
    std::string word;
    while(file >> word){
       ++word_count[word];
       ++wordCount;
    }
    for (const auto &[word, count] : word_count){
       std::cout << word << ": " << count << std::endl;
    }

    std::cout << "Number of words in " << filename << ": " <<wordCount << std::endl;
    return 0;
}