// Ira Pohl  Map example using hashed unordered_map
// March 2016

// This program asks the user for a file to
// open for reading.
// It then reads the file into a vector of strings
// Each string is a word that in the file was separated by white space
// It then uses an unordered map to count the number of occurences of each word

#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <iostream>

int main(){
    std::vector<std::string> words;
    std::string temp_str, file_name;
    std::cout << "What File do you want?\n";
    std::cin >> file_name;

    /*
    This line of code is reading from a file stream (fin) into a string (temp_str) until the end of the file is reached. For each successful read, the string (temp_str) is pushed into a vector called "words". The file stream is then closed once the end of the file is reached.
    It is a way to read in all the words from a text file and store them in a vector (words) for further processing.
    */
    std::ifstream fin(file_name); //fin used to open a file and 
    while (fin >> temp_str) // Will read up to eof()
        words.push_back(temp_str);
    fin.close();

    /*
    This line of code creates an unordered_map called "word_map", which is a container that stores elements in key-value pairs. The key is of type std::string and the value is of type size_t.

    The next line of code uses a range-based for loop to iterate over each element "w" in the "words" container. For each iteration, the operator ++word_map[w] is used. This operator first checks if the key "w" is present in the "word_map" container. If it is present, it increments the corresponding value by 1. If it is not present, it inserts the key-value pair (w, 1) into the container.

    In other words, this code iterates through all the elements of the "words" container and counts the frequency of each word by inserting them into the "word_map" container and incrementing the value when the word already exists as a key in the map.
    */
    std::unordered_map<std::string, size_t> word_map;
    for (const auto &w : words)
        ++word_map[w];

    
    /* This line is a for loop that iterates over each element in the "word_map" container. The "pair" variable is a reference to each element in the container, which is a key-value pair where the key is a string (word) and the value is the number of occurrences of that word. The loop uses the "auto" keyword to automatically determine the type of "pair" based on the type of "word_map". The loop then prints out the number of occurrences of the word, which is the value of "pair", and the word itself, which is the key of "pair". The "const" keyword is used to prevent any modifications to the elements of the container during iteration. */

    for (const auto &pair : word_map)
    {
        std::cout << pair.second << " occurrences of word '" << pair.first << "'\n";
    }
}