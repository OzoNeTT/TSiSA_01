#include <iostream>
#include <cmath>
#include <string>

double Fun(double x)
{
    return -sqrt(x)*sin(x);
}
int F(int n)
{
    int f, f1(1), f2(1), m(0);
    while(m < n - 1)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        ++m;
    }
    return f1;
}
void Fib(double a, double b, double eps)
{
    std::cout<<"\n\n\n\tМетод Фибоначчи:\n\n";
    double x1, x2, result_x, funcInX1, funcInX2;
    int N = 3;
    bool done = false;
    x1 = a + (double)F(N- 2)/ F(N) *(b - a);
    x2 = b - (double)F(N- 2)/ F(N) *(b - a);
    funcInX1 = Fun(x1);
    funcInX2 = Fun(x2);
    while(!done) {
        result_x = (a + b) / 2;
        std::cout << "Итерация № " << N << '\n'
                  << "x1 = " << x1 << "\t\tF(x1) = " << funcInX1
                  << "\nx2 = " << x2 << "\t\tF(x2) = " << funcInX2 << std::endl << result_x << " +- "
                  << std::to_string(fabs(b - a) / 2)
                  << '\n' << std::endl;
        N++;
        if (funcInX1 >= funcInX2) {
            a = x1;
            x1 = a + (double)F(N- 2)/ F(N) *(b - a);
            x2 = b - (double)F(N- 2)/ F(N) *(b - a);
            funcInX1 = Fun(x1);
            funcInX2 = Fun(x2);
        } else {
            b = x2;
            x1 = a + (double)F(N- 2)/ F(N) *(b - a);
            x2 = b - (double)F(N- 2)/ F(N) *(b - a);
            funcInX1 = Fun(x1);
            funcInX2 = Fun(x2);
        }

        if (fabs(b - a) <= eps) {
            done = true;
        }

    }
    result_x = (a + b) / 2;
    std::cout << "Итерация № " << N << '\n'
              << "x1 = " << x1 << "\t\tF(x1) = " << funcInX1
              << "\nx2 = " << x2 << "\t\tF(x2) = " << funcInX2 << std::endl << result_x << " +- "
              << std::to_string(fabs(b - a) / 2)
              << '\n' << std::endl;
    std::cout << "Результат:\nx = " << result_x << " +- " << std::to_string(fabs(b - a) / 2)
              << "\t\tF(x) = " << Fun(result_x)
              << "\nКоличество итераций: " << N;
}

int main() {
    double a = 0;
    double b = 3;
    double eps = 0.1;
    Fib(a, b, eps);
    return 0;
}