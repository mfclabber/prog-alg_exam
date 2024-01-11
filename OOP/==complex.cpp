// 5. ����������� ����樨 �ࠢ����� ���� ���������� �ᥫ �� ࠢ���⢮ (==).

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
    cout << "������ ����⢥���� ����: ";
    cin >> a;
    cout << "������ ������ ����: ";
    cin >> b;
}
 
void ComplexNumber::print() {
    cout << a << (b > 0? "+" : "") << b << "*i\n"; //����� �ᯮ�짮��� �ୠ�� ������, ����� �������� ����� if..else
}
 
bool ComplexNumber::operator ==(ComplexNumber& right){
    return (a == right.a and b == right.b);
}

int main() {
    ComplexNumber a, b, result;
    int answer;

    cout << "��᫮ A\n";
    a.read();
    cout << "��᫮ B\n";
    b.read();

    cout << (a == b);
}