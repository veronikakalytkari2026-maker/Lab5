// Лабораторна робота № 5.5
// Варіант 10
// Рекурсивне обчислення степеня дійсного числа x з цілим показником n:
//          | 1,            якщо n = 0
//   x^n =  | 1 / x^|n|,    якщо n < 0
//          | x * x^(n-1),  якщо n > 0
// Визначити та вивести рівень і глибину рекурсії.

#include <iostream>

using namespace std;

// x     - основа степеня
// n     - цілий показник степеня
// level - рівень поточного рекурсивного виклику (параметр-значення)
// depth - глибина рекурсії (параметр-посилання)
double Power(const double x, const int n, const int level, int &depth)
{
    if (level > depth)
        depth = level;

    cout << " level = " << level << endl;

    if (n == 0)                                        // базова задача
        return 1;
    else
        if (n < 0)
            return 1 / Power(x, -n, level + 1, depth); // x^n = 1 / x^|n|
        else
            return x * Power(x, n - 1, level + 1, depth); // x^n = x * x^(n-1)
}

int main()
{
    double x;
    int n;

    cout << "x = "; cin >> x;
    cout << "n = "; cin >> n;

    if (x == 0 && n < 0)
    {
        cout << "Помилка: 0 не можна підносити до від'ємного степеня" << endl;
        return 1;
    }

    int depth = 0;                           // початкове значення глибини
    double p = Power(x, n, 1, depth);        // 1 - початкове значення level

    cout << "x^n = " << p << endl;
    cout << "depth = " << depth << endl;

    return 0;
}