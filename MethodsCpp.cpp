#include <iostream>
using namespace std;

class point()
{
public:
    double getx() { 
        return x; };
    void setx(double v)
    {
        x = v;
    }
    point()
    {
        x = y = 0.0;
    }
}

const point &
operator+(const point &p1) {
    const point &sum = point(p1.x + this->x, p1.y + this->y);
    return sum;
}
