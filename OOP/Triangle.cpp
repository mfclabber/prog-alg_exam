// 7. Реализуйте класс Triangle для работы с треугольником. В главной программе поставьте в очередь несколько треугольников и прямоугольников.
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
 
class Triangle: public Figure{
private:
    double a, b, c;

public:
    Triangle (double a, double b, double c) : a(a), b(b), c(c) {}
    double getArea() const {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
    void getShow() const {cout << "*** Triangle ***" << endl;}
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

    figure[0] = new Triangle(1, 2, 3);
    figure[1] = new Triangle(2, 5, 6);

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