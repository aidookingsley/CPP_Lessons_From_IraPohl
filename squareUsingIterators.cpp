#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

template<class ForwardIterator>
void square(ForwardIterator first, ForwardIterator last){
    for (; first != last; first++)
        *first = (*first) * (*first);
}

int main(){
    std::vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> squared;
    std::vector<int> cubed;

    square(original.begin(), original.end());
    for (auto i : original)
        cout << i << '\t';
    cout << endl;
}