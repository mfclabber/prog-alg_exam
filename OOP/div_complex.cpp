// 1. ����������� ������ ������� ���� ���������� �ᥫ.

// ������ 2. ���⥩訥 �������� ������. �⠭����� �������

// 1. ����������� �����吝� ᯨ᮪ ��� �ந����쭮�� ⨯� ����⮢.

// 2. ����������� �����吝� ᯨ᮪ ��� �ந����쭮�� ⨯� ����⮢.

// 3. ����ந�� ������ ᬥ����� ��� ���, ��������� �९�����⥫��.

// 4. ����ந�� ������ ��樤��⭮�� ��� ���, ��������� �९�����⥫��.

// 5. �����஢��� ॠ������ ����� Graph ��� �।�⠢����� ��� � ���� ������ ��樤��⭮��.

// 6. �����஢��� ॠ������ ����� Graph ��� �।�⠢����� ��� � ���� ᯨ᪠ ॡ��.

// 7. ���᫨�� �筮� � �ਡ�������� (�६� ��⮤���) ���祭�� �ந������� �㭪樨 y=x*x � �窥 x=1 � 蠣�� h=1 � h=0.001.

// 8. ������� �ணࠬ�� ��� ��宦����� ��ன �ந������� �㭪樨 y = 2 * x4 � �窥 x=1 � 蠣�� h=0.01, �ࠢ���� � ��� ���祭���.

// 9. ���᫨�� ��।������ ��⥣ࠫ ������ �᫥��묨 ��⮤���, �ࠢ���� � ��� ���祭���.

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
    cout << "������ ����⢥���� ����: ";
    cin >> a;
    cout << "������ ������ ����: ";
    cin >> b;
}
 
void ComplexNumber::print() {
    cout << a << (b > 0? "+" : "") << b << "*i\n"; //����� �ᯮ�짮��� �ୠ�� ������, ����� �������� ����� if..else
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

    cout << "��᫮ �\n";
    a.read();
    cout << "��᫮ B\n";
    b.read();

    result = a.divide(b);

    cout << "�������: ";
    result.print();
}