#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

class gen
{
public:
    gen(double x_zero, double increment) : x(x_zero), incr(increment) {}
    double operator()()
    {
        x += incr;
        return x * x;
    }

private:
    double x, incr;
};

double integrate(gen g, int n)
{
    std::vector<double> fx(n);

    generate(fx.begin(), fx.end(), g);
    return (accumulate(fx.begin(), fx.end(), 0.0) / n); // Simpson style numerical integration
}

int main()
{
    const int n = 10000;

    gen g(0.0, 1.0 / n);
    std::cout << "integration program x**2" << std::endl;
    std::cout << integrate(g, n) << std::endl;
}