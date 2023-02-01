#include <iostream>
#include <string>
#include <stack>

template <class T>
class myStack {
public:
    void push(const T& item) {
        s.push(item);
    }
    T pop() {
        if(s.empty())
            return T();
        T item = s.top();
        s.pop();
        return item;
    }
    bool empty() const {
        return s.empty();
    }
    size_t size() const {
        return s.size();
    }
private:
    std::stack<T> s;
};

int main() {
    myStack<char> stack;
    std::string str;
    std::cout<< "Enter a sentence: ";
    std::getline(std::cin,  str);
    //std::cin.get();

    std::cout << "Original String: " << str << std::endl;

    // push characters onto stack
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }

    // pop characters from stack and store in reversed string
    std::string reversed;
    while (!stack.empty()) {
        reversed += stack.pop();
    }

    std::cout << "Reversed String: " << reversed << std::endl;

    return 0;
}
// I asked God for a side and I got You
