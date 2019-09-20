#include <iostream>
#include <cmath>
#include <string>

double Fun(double x)
{
    return -sqrt(x)*sin(x);
}

int F(int n) {
    if (n == 1 || n == 2 )
        return 1;
    else
        return F(n - 1) + F(n - 2);
}
void Fib(double a_old, double b_old, double eps)
{
    std::cout<<"\n\n\n\tМетод Фибоначчи:\n\n";
    double x1, x2, result_x, funcInX1, funcInX2;
    int N = 3;
    bool done = false;
    double a = a_old;
    double b = b_old;
    while(!done) {

        a = a_old;
        b = b_old;
        x1 = a + (double)F(N- 2)/ F(N) *(b - a);
        x2 = b - (double)F(N- 2)/ F(N) *(b - a);
        funcInX1 = Fun(x1);
        funcInX2 = Fun(x2);
        for (int i = 0; i < N - 2 ; i++) {
            if (funcInX1 > funcInX2) {
                a = x1;
                x1 = x2;
                funcInX1 = funcInX2;
                x2 = b - (double)F(N - i - 2) / F(N - i) * (b - a) ;
                funcInX2 = Fun(x2);
            }
            else if(funcInX1 < funcInX2) {

                b = x2;
                x2 = x1;
                funcInX2 = funcInX1;
                x1 = a + (double) F(N - i - 2) / F(N - i) * (b - a);
                funcInX1 = Fun(x1);
            }

        }

        result_x = (a + b) / 2;
        std::cout << "Итерация № " << N << '\n'
                  << "x1 = " << x1 << "\t\tF(x1) = " << funcInX1
                  << "\nx2 = " << x2 << "\t\tF(x2) = " << funcInX2 << std::endl << result_x << " +- "
                  << std::to_string(fabs(b - a) / 2)
                  << '\n' << std::endl;

        if (fabs(b - a) <= eps) {
            done = true;
        }
        N++;

    }
    result_x = (a + b) / 2;

    std::cout << "Результат:\nx = " << result_x << " +- " << std::to_string(fabs(b - a) / 2)
              << "\t\tF(x) = " << Fun(result_x)
              << "\nКоличество итераций: " << N - 1;
}

int main() {
    double a = 0;
    double b = 3;
    double eps = 0.1;
    Fib(a, b, eps);
    return 0;
}