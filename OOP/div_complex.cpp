// 1. Реализовать операцию деления двух комплексных чисел.

#include <iostream>

using namespace std;
 
class ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    ComplexNumber divide(ComplexNumber&);
    void print();
    void read();

private:
    double a, b;
};
 
ComplexNumber::ComplexNumber() {
    a = 0;
    b = 0;
}
 
ComplexNumber::ComplexNumber(double a, double b) {
    this->a = a;
    this->b = b;
}
 
void ComplexNumber::read() {
    cout << "Введите вещественную часть: : ";
    cin >> a;
    cout << "Введите мнимую часть: �: ";
    cin >> b;
}
 
void ComplexNumber::print() {
    cout << a << (b > 0? "+" : "") << b << "*i\n"; //здесь использован тернарный оператор, можно заменить простым if..else
}
 
ComplexNumber ComplexNumber::divide(ComplexNumber &right) {
    double a = this->a,
        b = this->b,
        c = right.a,
        d = right.b;

    double resultA = (a*c + b*d)/(c*c + d*d),
        resultB = (b*c - a*d)/(c*c + d*d);

    return ComplexNumber(resultA, resultB);
}

int main() {
    ComplexNumber a, b, result;
    int answer;

    cout << "число А\n";
    a.read();
    cout << "Число В\n";
    b.read();

    result = a.divide(b);

    cout << "Результат: ";
    result.print();
}