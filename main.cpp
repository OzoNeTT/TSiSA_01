#include <iostream>
#include <cmath>
#include <string>
#include <vector>

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
    std::cout<<"\n\n\n\tFibonacci Search:\n\n";
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
        result_x = (begin_new + end_new) / 2;
        std::cout << "Number of points: " << N
                  << "\t\tx:= " << result_x << " +- "
                  << std::to_string(fabs(end_new - begin_new) / 2)
                  << "\t\tF(x):= " << Function(result_x)
                  << '\n';
        N++;
    }
    result_x = (begin_new + end_new) / 2;

    std::cout << "Result:\nx = " << result_x << " +- " << std::to_string(fabs(end_new - begin_new) / 2)
              << "\t\tF(x) = " << Function(result_x)
              << "\nNumber of points: " << N - 1;
}

void optimalPassiveSearch(double begin, double end, double epsilon) {

    std::cout<<"\n\n\n\tPassive Search:\n\n";
    int N = 0, iterator, counter = 0;
    bool done = false;
    double best_x = 0;
    double best_y = 1;
    std::vector<double> x_storage;
    while(!done) {
        N++;
        x_storage.resize(N+2);
        counter = 0;

        for(double element = begin; element <= end; element += fabs((end - begin)/ (N + 1))) {
            x_storage[counter++] = element;
        }
        for (iterator = 1; iterator < N + 2; iterator++) {
            if (Function(x_storage[iterator]) <= best_y) {
                best_y = Function(x_storage[iterator]);
                best_x = x_storage[iterator];
            }
            if (fabs((end - begin)/ N) <= epsilon) {
                done = true;
            }

        }

        x_storage.clear();

        std::cout << "Number of points: " << N
                  << "\t\tx:= " << best_x << " +- "
                  << std::to_string(fabs((end - begin)/ (N+ 1)))
                  << "\t\tF(x):= " << best_y
                  << '\n';


    }
    std::cout << "Result:\nx = " << best_x << " +- " << std::to_string(fabs((end - begin)/ (N+ 1)))
              << "\t\tF(x) = " << Function(best_x)
              << "\nNumber of points: " << N;

}
int main() {
    double a = 0;
    double b = 3;
    double eps = 0.1;
    Fib(a, b, eps);
    optimalPassiveSearch(a, b, eps);
    return 0;
}