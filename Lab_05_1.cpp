#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Прототип функції
double f(const double a, const double b, const double c);

int main()
{
    double s, t;

    cout << "s = ";
    cin >> s;

    cout << "t = ";
    cin >> t;

    double result = (f(t, s, 2) + f(1, s + t, t - s)) /
                    (1 + pow(f(1, 1, t * t + s * s), 2));

    cout << fixed << setprecision(6);
    cout << "F = " << result << endl;

    return 0;
}

// Визначення функції
double f(const double a, const double b, const double c)
{
    return (a + b + c) /
           (pow(sin(a * b), 2) + c * c);
}