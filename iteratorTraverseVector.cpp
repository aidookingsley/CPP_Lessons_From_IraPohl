#include <iostream>
#include <vector>

// an example of using an iterator to traverse a vector
int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it;
    for (it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
