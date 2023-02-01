#include <iostream>
using namespace std;
class DecFraction{
    int numerator, denom;
    public:
    DecFraction(int num, int denm) {
        numerator = num;
        denom = denm;
    }

    // conversion operator: converts fraction to float value and returns it
    operator float() const {
        return float(numerator) / float(denom);
    }
};

int main() {
    DecFraction df( 3, 5);  //object of class
    float res_val = df;     // calls conversion operator
    cout << "The resultant value of given fraction (3,5)=" << res_val;
    return 0;
}