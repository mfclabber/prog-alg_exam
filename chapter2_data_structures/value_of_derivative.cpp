/*
7. Вычислить точное и приближенное (тремя методами) значения производной функции y=x*x в точке x=1 с шагом h=1 и ^h=0.001.
    1. dy/dx = (y(x + dx) - y(x)) / dx
    2. dy/dx = (y(x) - y(x - dx)) / dx
    3. dy/dx = (y(x + dx) - y(x - dx)) / 2dx
*/

#include <iostream>
#include <vector>
#include <string>

double f(double x){
    return x*x;
}

int main(){
    int x = 1;
    double dx = 0.001; double dy;

    // 1
    dy = (f(double(x) + dx) - f(x)) / dx;
    std::cout << dy << "\n";

    // 2
    dy = (f(x) - f(double(x) - dx)) / dx;
    std::cout << dy << "\n";

    // 3
    dy = (f(double(x) + dx) - f(double(x) - dx)) / double(2*dx);
    std::cout << dy;
}