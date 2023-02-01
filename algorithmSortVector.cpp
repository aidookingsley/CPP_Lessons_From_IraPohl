#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myVector = {5, 1, 4, 2, 3};
    std::sort(myVector.begin(), myVector.end());
    for (auto i : myVector) {
        std::cout << i << " ";
    }
    std::cout << "\nThe size of myVector is: " << myVector.size() << std::endl;
    return 0;
}
