// 3. ����������� ����樨 +=, -= ��� ���������� �ᥫ.

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
    cout << "������ ����⢥���� ����: ";
    cin >> a;
    cout << "������ ������ ����: ";
    cin >> b;
}
 
void ComplexNumber::print() {
    cout << a << (b > 0? "+" : "") << b << "*i\n"; //����� �ᯮ�짮��� �ୠ�� ������, ����� �������� ����� if..else
}
 
double ComplexNumber::mod() {

    double result = sqrt(pow(this->a, 2) + pow(this->b, 2));
    cout << "�����: " << result;
    return result;
}

int main() {
    ComplexNumber a;
    int answer;
    double result;

    cout << "��᫮\n";
    a.read();

    result = a.mod();
}