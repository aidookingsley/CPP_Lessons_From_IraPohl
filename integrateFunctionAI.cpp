// Here is an example implementation of the trapezoidal rule for numerical integration:
#include <cmath>
#include <iostream>

double integrate(double a, double b, int n, double (*f)(double))
{
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

// example usage
double f(double x)
{
    return std::sin(x);
}

int main()
{
    double a = 0.0;
    double b = M_PI;
    int n = 1000;

    double result = integrate(a, b, n, f);

    std::cout << "integral of sin(x) from 0 to pi = " << result << std::endl;

    return 0;
}
