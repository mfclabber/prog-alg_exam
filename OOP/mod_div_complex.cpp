// 4. ����������� ����樨 *= � /= ��� ���������� �ᥫ.

#include <iostream>
#include <math.h>

using namespace std;
 
class ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    ComplexNumber operator *=(ComplexNumber& right);
    ComplexNumber operator /=(ComplexNumber& right);
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
 
ComplexNumber ComplexNumber::operator *=(ComplexNumber& right){
    double c = right.a,
        d = right.b;
    a = a*c - b*d;
    b = b*c + a*d;
    return *this;
}

ComplexNumber ComplexNumber::operator /=(ComplexNumber& right){
    double c = right.a,
        d = right.b;

    a = (a*c + b*d)/(c*c + d*d);
    b = (b*c - a*d)/(c*c + d*d);

    return *this;
}

int main() {
    ComplexNumber a, b, result;
    int answer;

    cout << "��᫮ A\n";
    a.read();
    cout << "��᫮ B\n";
    b.read();

    a *= b;
    a.print();

    a /= b;
    a.print();
}