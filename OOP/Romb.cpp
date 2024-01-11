//9. Реализуйте класс Romb для работы с ромбом. В главной программе поставьте в очередь несколько ромбов и прямоугольников.
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
 
double pi = 4 * atan(1);

class Figure{
public: 
    virtual double getArea() const = 0;
    virtual void getShow() const = 0;
};
 
class Romb: public Figure{
private:
    double a, b; // длина диагоналей

public:
    Romb (double a, double b) : a(a), b(b) {}
    double getArea() const {return a * b / 2;}
    void getShow() const {cout << "*** Romb ***" << endl;}
};

class Rectangle: public Figure{
private:
    double a, b;

public:
    Rectangle(double a, double b) : a(a), b(b){}
    double getArea() const {return a*b;}
    void getShow() const {cout << "*** Rectangle ***" << endl;}
};
 
int main() 
{
    Figure *figure[4];

    figure[0] = new Romb(1, 2);
    figure[1] = new Romb(2, 5);

    figure[2] = new Rectangle(2, 6);
    figure[3] = new Rectangle(3, 5);

    queue<Figure*> q;
    for (int i=0; i < 4; ++i){
        q.push(figure[i]);
        q.back()->getShow();
    }
    
    for (int i=0; i < 4; ++i){
        delete figure[i];
    }
}