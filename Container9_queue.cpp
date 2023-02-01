#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "Front element: " << q.front() << std::endl;  // 1
    q.pop();
    std::cout << "Front element: " << q.front() << std::endl;  // 2
    return 0;
}
