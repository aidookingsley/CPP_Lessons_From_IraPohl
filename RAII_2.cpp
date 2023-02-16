#include <iostream>
#include <memory>

class ManagedInt
{
public:
    ManagedInt() : ptr(new int(0))
    {
        std::cout << "ManagedInt: " << ptr << "\n";
    }
    ~ManagedInt()
    {
        delete ptr;
        std::cout << "~ManagedInt: " << ptr << "\n";
    }
    int *get() { return ptr; }

private:
    int *ptr;
};

int main()
{
    ManagedInt i;
    *i.get() = 42;
    std::cout << *i.get() << std::endl;
    return 0;
}