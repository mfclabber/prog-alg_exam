// 5. Реализовать операции сравнения двух комплексных чисел на равенство (==).

#include <iostream>
#include <math.h>

using namespace std;
 
class ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    bool operator ==(ComplexNumber& right);
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
 
bool ComplexNumber::operator ==(ComplexNumber& right){
    return (a == right.a and b == right.b);
}

int main() {
    ComplexNumber a, b, result;
    int answer;

    cout << "Число A\n";
    a.read();
    cout << "Число B\n";
    b.read();

    cout << (a == b);
}