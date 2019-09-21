#include <iostream>
#include <cmath>
#include <string>

double Function(double x){
    return -sqrt(x)*sin(x);
}

int FibonacciNumber(int n) {
    if (n == 1 || n == 2 )
        return 1;
    else
        return FibonacciNumber(n - 1) + FibonacciNumber(n - 2);
}

void Fib(double begin, double end, double epsilon){
    std::cout<<"\n\n\n\tМетод Фибоначчи:\n\n";
    double begin_new, end_new, x1, x2, result_x, function_in_x1, function_in_x2;
    int N = 3;
    bool done = false;
    while(!done) {

        begin_new = begin;
        end_new = end;
        x1 = begin_new + (double)FibonacciNumber(N- 2)/ FibonacciNumber(N) *(end_new - begin_new);
        x2 = end_new - (double)FibonacciNumber(N- 2)/ FibonacciNumber(N) *(end_new - begin_new);

        function_in_x1 = Function(x1);
        function_in_x2 = Function(x2);

        for (int i = 0; i < N - 2 ; i++) {
            if (function_in_x1 > function_in_x2) {
                begin_new = x1;
                x1 = x2;
                function_in_x1 = function_in_x2;
                x2 = end_new - (double)FibonacciNumber(N - i - 2) / FibonacciNumber(N - i) * (end_new - begin_new) ;
                function_in_x2 = Function(x2);
            }
            else if(function_in_x1 < function_in_x2) {

                end_new = x2;
                x2 = x1;
                function_in_x2 = function_in_x1;
                x1 = begin_new + (double) FibonacciNumber(N - i - 2) / FibonacciNumber(N - i) * (end_new - begin_new);
                function_in_x1 = Function(x1);
            }
            if (fabs(end_new - begin_new) <= epsilon) {
                done = true;
                break;
            }
        }
        //result_x = (begin_new + b) / 2;
        //std::cout << "Итерация № " << N << '\n'
        //          << "x1 = " << x1 << "\t\tF(x1) = " << function_in_x1
        //          << "\nx2 = " << x2 << "\t\tF(x2) = " << funcInX2 << std::endl << result_x << " +- "
        //          << std::to_string(fabs(b - begin_new) / 2)
        //          << '\n' << std::endl;
        N++;
    }
    result_x = (begin_new + end_new) / 2;

    std::cout << "Результат:\nx = " << result_x << " +- " << std::to_string(fabs(end_new - begin_new) / 2)
              << "\t\tF(x) = " << Function(result_x)
              << "\nКоличество итераций: " << N - 1;
}

void optimalPassiveSearch(double begin, double end, double epsilon) {

    std::cout<<"\n\n\n\tМетод Пассивного поиска:\n\n";
    int N = std::ceil((end- begin) / epsilon), iterator, counter = 0;

    auto * x_storage = new double[N];
    for (double element = begin; element <= end; element += epsilon)
        x_storage[counter++] = element;

    double result_x;

    for (iterator = 0; iterator < N; iterator++){
        if(Function(x_storage[iterator]) < Function(x_storage[iterator + 1])) {
            result_x = (x_storage[iterator - 1] + x_storage[ iterator + 1]) / 2;
            break;
        }
    }

    std::cout << "Количество необходимых точек: " << N - 2<< '\n'
              << "x = " << result_x
              <<  " +- "
              << std::to_string(epsilon / 2)
              << "\t\tF(x) = " << Function(result_x)
              << '\n' << std::endl;

    delete[] x_storage;
}
int main() {
    double a = 0;
    double b = 3;
    double eps = 0.1;
    Fib(a, b, eps);
    optimalPassiveSearch(a, b, eps);
    return 0;
}