#include <iostream>
using namespace std;
class point{
    public:
    point(double x=0.0, double y=0.0):x(x),y(y){} //constructor
    double getx() { return x; }
    void setx(double v) { v = x; }

    private:
        double x, y;
};
/*
A special method constructor

point(){x=y=0.0;}    ==>ordinary assignment

or
point(){this->x=0.0; this->y=0.0;} ==> pointer assignment

or best
point():x(0.0),y(0.0){}  ==> initializing list

default constructor - the constructor whose signature is void


it is useful to have multiple ways to initialize an object like point.

point(double x, double y)
{this -> x = x; this->y = y;}  //pointer notaion

this is iused to disambiguate
this lets ambiguity be resolved x=x; would not work
better use initialization syntax
point(double x, double y):x(x), y(y){}
1st x is a member, 2nd is an expression or an argument

*/


/*
~ destructor

deallocator when item goes out of scope

syntax within class ~classname(){....}

Typical use is for calling delete to deallocate to the heap - what if you forget

Answr: Bad manners - memmory leak
*/
