// 1. Реализовать операцию деления двух комплексных чисел.

// Раздел 2. Простейшие структуры данных. Стандартные алгоритмы

// 1. Реализовать односвязный список для произвольного типа элементов.

// 2. Реализовать двухсвязный список для произвольного типа элементов.

// 3. Построить матрицу смежности для графа, заданного преподавателем.

// 4. Построить матрицу инцидентности для графа, заданного преподавателем.

// 5. Адаптировать реализацию класса Graph для представления графа в виде матрицы инцидентности.

// 6. Адаптировать реализацию класса Graph для представления графа в виде списка ребер.

// 7. Вычислить точное и приближенное (тремя методами) значения производной функции y=x*x в точке x=1 с шагом h=1 и h=0.001.

// 8. Написать программу для нахождения второй производной функции y = 2 * x4 в точке x=1 с шагом h=0.01, сравнить с точным значением.

// 9. Вычислить определенный интеграл четырьмя численными методами, сравнить с точным значением.

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
    cout << "Введите вещественную часть: ";
    cin >> a;
    cout << "Введите мнимую часть: ";
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

    cout << "Число А\n";
    a.read();
    cout << "Число B\n";
    b.read();

    result = a.divide(b);

    cout << "Результат: ";
    result.print();
}