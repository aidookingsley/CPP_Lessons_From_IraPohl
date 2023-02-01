// POLYMORPHISM - FUNCTION OVERLOADING;
#include <iostream>
#include <string>
using namespace std;

class Summation
{
public:
    int Add(int num1, int num2)
    {
        return num1 + num2;
    }
    int Add(int num1, int num2, int num3)
    {
        return num1 + num2 + num3;
    }
    string Add(string s1, string s2)
    {
        return s1 + s2;
    }
    double Add(double num1, double num2)
    {
        return num1 + num2;
    }
};

int main(void)
{
    Summation obj;
    cout << obj.Add(20, 15) << endl;
    cout << obj.Add(81, 100, 10) << endl;
    cout << obj.Add(10.78, 9.56) << endl;
    cout << obj.Add("Hello", " Adekyensroma");

    return 0;
}