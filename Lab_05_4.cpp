#include <iostream>

using namespace std;

// Загальний множник добутку
double f(const int N, const int i)
{
    return (1. * i * N) / (1. * i * i + 1. * N * N);
}

// 0) ітераційний спосіб (для контролю)
double P0(const int N, const int M)
{
    double p = 1;
    for (int i = N; i <= M; i++)
        p *= f(N, i);
    return p;
}

// 1) обчислення на рекурсивному спуску, параметр i зростає
double P1(const int N, const int M, const int i, double t)
{
    if (i > M)
        return t;
    else
        return P1(N, M, i + 1, t * f(N, i));
}

// 2) обчислення на рекурсивному спуску, параметр i спадає
double P2(const int N, const int M, const int i, double t)
{
    if (i < N)
        return t;
    else
        return P2(N, M, i - 1, t * f(N, i));
}

// 3) обчислення на рекурсивному підйомі, параметр i зростає
double P3(const int N, const int M, const int i)
{
    if (i > M)
        return 1;
    else
        return f(N, i) * P3(N, M, i + 1);
}

// 4) обчислення на рекурсивному підйомі, параметр i спадає
double P4(const int N, const int M, const int i)
{
    if (i < N)
        return 1;
    else
        return f(N, i) * P4(N, M, i - 1);
}

int main()
{
    int N;
    const int M = 16;   // верхня межа добутку

    cout << "N = "; cin >> N;

    cout << "(iter)        P0 = " << P0(N, M)          << endl;
    cout << "(rec down ++) P1 = " << P1(N, M, N, 1)    << endl;
    cout << "(rec down --) P2 = " << P2(N, M, M, 1)    << endl;
    cout << "(rec up ++)   P3 = " << P3(N, M, N)       << endl;
    cout << "(rec up --)   P4 = " << P4(N, M, M)       << endl;
    
    return 0;
}