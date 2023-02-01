#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> flist = {1, 2, 3, 4, 5};
    flist.push_front(0);  // Add element to the front of the list
    //flist.pop_front();    // Remove the first element
    std::cout << "First element: " << flist.front() << std::endl;
    std::cout << "List size: " << std::distance(flist.begin(), flist.end()) << std::endl;
    return 0;
}
