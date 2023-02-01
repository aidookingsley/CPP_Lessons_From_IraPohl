#include <iostream>
using namespace std;

typedef enum days
{
    SUN,
    MON,
    TUES,
    WED,
    THUR,
    FRI,
    SAT
} days;

inline days operator++(days d)
{
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

ostream &operator<<(ostream &out, const days &d)
{
    switch (d)
    {
    case SUN:
        out << "Sunday";
        break;
    case MON:
        out << "Monday";
        break;
    case TUES:
        out << "Tuesday";
        break;
    case WED:
        out << "Wednesday";
        break;
    case THUR:
        out << "Thursday";
        break;
    case FRI:
        out << "Friday";
        break;
    case SAT:
        out << "Saturday";
        break;
    }
    return out;
}

int main()
{
    days d = MON, e;
    e = ++d;
    cout << d << '\t' << e << endl;
}

// days operator++(days &d){
//     return d = static_cast<int> (d) + 1 % 7;
// }
