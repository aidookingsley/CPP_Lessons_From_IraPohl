#include <iostream>
using namespace std;

int idCnt = 0;

template <class T>
class MoveableClass
{
private:
    T *_resource;
    int _id;

public:
    // 2
    MoveableClass(T *ptr = nullptr)
    {
        _resource = ptr;
        _id = ++idCnt;
        cout << _id << " constructor " << sizeof(*ptr) << " byte\n";
    }
    // 3
    ~MoveableClass()
    {
        cout << _id << " Destructor " << (_resource != nullptr ? "(delete)\n" : "\n");
        delete _resource;
    }
    // 4 copy constructor
    MoveableClass(const MoveableClass &source)
    {
        if (source._resource != nullptr)
        {
            _resource = new T;
            *_resource = *source._resource;
        }
        _id = ++idCnt;
        cout << _id << " Copy Constr. from " << source._id << "\n";
    }
    // 5 move constructor
    MoveableClass(MoveableClass &&source)
    {
        _resource = source._resource;
        source._resource = nullptr;
        _id = ++idCnt;
        cout << _id << " Move Constr. from " << source._id << "\n";
    }
    // 6
    MoveableClass &operator=(const MoveableClass &source)
    {
        cout << _id << " Copy Assignment from " << source._id << "\n";
        if (&source == this)
            return *this;
        delete _resource;
        _resource = nullptr;

        if (source._resource != nullptr)
        {
            _resource = new T;
            *_resource = *source._resource;
        }
        return *this;
    }
    // 7 move assignment operator
    MoveableClass &operator=(MoveableClass &&source)
    {
        cout << _id << " Move Assignemnt from " << source._id << "\n";
        if (&source == this)
            return *this;
        _resource = source._resource;
        source._resource = nullptr;
        return *this;
    }
};

int main()
{
    // 8
    MoveableClass<double> mc_d(new double);

    MoveableClass<long double> mc_ld(new long double);

    // 9
    MoveableClass<double> mc_d2(mc_d);

    MoveableClass<double> mc_d3 = mc_d;

    // 10
    MoveableClass<double> mc_d5(std::move(mc_d));

    // 11
    mc_d = std::move(mc_d5);

    return 0;
}