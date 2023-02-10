#include <iostream>
using namespace std;

class MyClass
{
public:
    int _val;
    MyClass(int val) { _val = val; }
    ~MyClass() { cout << "~MyClass\n"; }
    MyClass returnCopy() { return *this; }
    MyClass &returnReference() { return *this; }
};

void myFun1(int &param) { param *= 2; }

int main()
{
    int m{10};
    myFun1(m);
    cout << "m = " << m << endl;

    MyClass mc(5);
    cout << "mc._val (copy) = " << mc.returnCopy()._val << endl;

    cout << "mc._val (reference) = " << mc.returnReference()._val << endl;

    return 0;
}