#include <iostream>
#include <cmath>

using namespace std;

double y(const double x);

int main()
{
    double fp, fk, z;
    int n;

    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n  = "; cin >> n;

    double df = (fk - fp) / n;

    cout << "-------------------------" << endl;
    cout << "|   f   |       z       |" << endl;
    cout << "-------------------------" << endl;

    double f = fp;
    while (f <= fk + df / 2)    // допуск на похибку double
    {
        z = y(f / 2) + pow(y(f + 1), 2) + y(2 * f);
        cout << "| " << f << "\t| " << z << "\t|" << endl;
        f += df;
    }
    cout << "-------------------------" << endl;

    return 0;
}

double y(const double x)
{
    if (fabs(x) >= 1)
        return exp(x) / (1 + exp(x) + sin(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;           // перший доданок (j = 0)
        S = a;
        do
        {
            j++;
            double R = -x * x / ((2.0 * j - 1) * (2.0 * j));   // коефіцієнт рекурентності
            a *= R;
            S += a;
        } while (j < 8);
        return S;
    }
}