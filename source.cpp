#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

double Function(double x){
    return -sqrt(x)*sin(x);
}

int FibonacciNumber(int n) {
    return (n == 1 || n == 2) ? 1 : FibonacciNumber(n - 1) + FibonacciNumber(n -2);
}

void PrintPoint(int N, double result_x, double interval) {
    std::cout << "Number of points: " << N
              << "\t\tx = " << std::fixed << std::setprecision(6) << result_x
              << "\t\tIndefinite interval: " << std::fixed << std::setprecision(6) << interval
              << "\t\tF(x):= " << std::fixed << std::setprecision(6) << Function(result_x) << '\n';
}

void PrintPointForReport(double a, double b, double l) {
    std::cout<< a << " | " << b << " | " << l << " | " << Function(a) << " | " << Function(b) << '\n';
}
void PrintResult(int N, double result_x, double interval){
    std::cout << "Result:\nx = " << std::fixed << std::setprecision(6) << result_x
              << "\t\tIndefinite interval: " << std::fixed << std::setprecision(6) << interval
              << "\t\tF(x) = " << std::fixed << std::setprecision(6) << Function(result_x)
              << "\nNumber of points: " << N;
}

void FibonacciSearch(double begin, double end, double epsilon){
    std::cout<<"\n\n\n\tFibonacci Search:\n\n";
    double begin_new, end_new, x1, x2, function_in_x1, function_in_x2;
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
            if (fabs(end_new - begin_new)  <= epsilon) {
                done = true;
                break;
            }
        }
        PrintPoint(N - 2, (begin_new + end_new) / 2,fabs(end_new - begin_new) );
        //PrintPointForReport(begin_new, end_new, fabs(end_new - begin_new));
        N++;
    }
    PrintResult(N - 3, (begin_new + end_new) / 2,fabs(end_new - begin_new) / 2 );
}

void optimalPassiveSearch(double begin, double end, double epsilon) {

    std::cout<<"\n\n\n\tPassive Search:\n\n";

    int N = std::ceil((end- begin) / epsilon);
    std::vector<double> x_storage;
    double result_x;
    int counter = 0;

    for (double element = begin + epsilon; element <= end; element += epsilon)
        x_storage.push_back(element);

    for (int iterator = 0; iterator < N; iterator++){
        if(Function(x_storage[iterator]) < Function(x_storage[iterator + 1])) {
            result_x = (x_storage[iterator - 1] + x_storage[ iterator + 1]) / 2;
            break;
        }
    }

    for(auto iterator : x_storage) {
        counter++;
        std::cout <<counter << " | " <<  iterator << " | " << Function(iterator) << std::endl;
    }

    std::cout << "\nNumber of points: " << N - 1<< '\n'
              << "Extremum: " << result_x
              <<  "\t\tInterval: "
              << std::to_string(epsilon)
              << "\t\tFunction: " << Function(result_x)
              << '\n' << std::endl;

    x_storage.clear();
}


int main() {
    double begin, end, epsilon;
    std::string userChoice;
    std::cout << "Hello, user! This is test app =)\n";
    while(userChoice != "n") {
        std::cout << "\tEnter value \'a\'\n>> ";

        while(!(std::cin >> begin)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Not a value, try again\n>> ";
        }
        std::cout << "Enter value \'b\'\n>> ";
        while(!(std::cin >> end)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Not a value, try again\n>> ";
        }
        std::cout << "Enter epsilon\n>> ";
        while(!(std::cin >> epsilon)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Not a value, try again\n>> ";
        }

        FibonacciSearch(begin, end, epsilon);
        optimalPassiveSearch(begin, end, epsilon);
        userChoice = "";
        while(userChoice != "n" && userChoice !="y") {
            std::cout << "\nWant again? (y/n): ";
            std::cin.clear();
            std::cin >> userChoice;
        }
    }
    return 0;
}