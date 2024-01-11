// 3. Реализовать операции +=, -= для комплексных чисел.

#include <iostream>
#include <math.h>

using namespace std;
 
class ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    double mod();
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
    cout << "Введите вещественную часть: ";
    cin >> a;
    cout << "Введите мнимую часть: ";
    cin >> b;
}
 
void ComplexNumber::print() {
    cout << a << (b > 0? "+" : "") << b << "*i\n"; //здесь использован тернарный оператор, можно заменить простым if..else
}
 
double ComplexNumber::mod() {

    double result = sqrt(pow(this->a, 2) + pow(this->b, 2));
    cout << "Модуль: " << result;
    return result;
}

int main() {
    ComplexNumber a;
    int answer;
    double result;

    cout << "Число\n";
    a.read();

    result = a.mod();
}