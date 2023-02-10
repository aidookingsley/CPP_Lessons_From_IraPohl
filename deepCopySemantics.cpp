#include <iostream>

using namespace std;

class MyCopy
{
public:
    // 1
    double *_myNumber;
    string _myName;
    MyCopy() // default constructor
    {
        cout << "Constructor\n";
        _myNumber = new double{0.0};
    }

    MyCopy(const MyCopy &source) // copy constructor
    {
        cout << "Copy Constructor\n";
        _myNumber = new double{0.0};
        *_myNumber = *source._myNumber;
    }

    MyCopy &operator=(const MyCopy &source) // copy assignemnt operator
    {
        cout << "Copy Assignment\n";
        *_myNumber = *source._myNumber;
        return *this;
    }
    ~MyCopy()
    {
        cout << "Destructor\n";
        delete _myNumber;
    }
    void printValueAndHandle()
    {
        cout << _myName << " heap address = " << _myNumber;
        cout << ", value = " << (_myNumber != nullptr ? *_myNumber : 0.0) << endl;
    }
};

int main()
{
    // 5
    MyCopy s1;
    s1._myName = "s1";
    *s1._myNumber = 42.0;

    MyCopy s2;
    s2._myName = "s2";
    *s2._myNumber = 23.0;

    // 6
    s1.printValueAndHandle();
    s2.printValueAndHandle();

    // 7
    s2 = s1;
    s2.printValueAndHandle();
}