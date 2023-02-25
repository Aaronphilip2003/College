#include <iostream>
using namespace std;
class Shape
{
    float base;
    float height;
    float length;
    double breadth;
    float side;
    double radius;

public:
    Shape()d;

    void area(float b, float h);
    void area(float l, double b);
    void area(int s);
    void area(float r);
};

Shape::Shape()
{
    base = 0;
    height = 0;
    length = 0;
    breadth = 0;
    side = 0;
    radius = 0;
}

void Shape::area(float b, float h)
{
    cout << "Area of Triangle:" << 0.5 * b * h << endl;
}

void Shape::area(float l, double b)
{
    cout << "Area of Rectangle:" << l * b << endl;
}

void Shape::area(int s)
{
    cout << "Area of Square:" << s * s << endl;
}

void Shape::area(float r)
{
    cout << "Area of Circle:" << 3.14 * r * r << endl;
}

int main()
{
    Shape a;
    a.area(3);
    a.area(1.1, 1.1111000);
    a.area(5);
    a.area(5.1, 6.1);
    return 0;
}