#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    pq.push(-5);
    pq.push(-3);
    pq.push(-7);
    std::cout << "Top element: " << pq.top() << std::endl;  // 7
    pq.pop();
    std::cout << "Top element: " << pq.top() << std::endl;  // 5
    return 0;
}
