// 6. Реализуйте класс Circle для работы с кругом. В главной программе поставьте в очередь несколько кругов и прямоугольников.
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
 
class Circle: public Figure{
private:
    double r;

public:
    Circle (double r) : r(r) {}
    double getArea() const {return pi*r*r;}
    void getShow() const {cout << "*** Circle ***" << endl;}
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

    figure[0] = new Circle(2);
    figure[1] = new Circle(5);

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