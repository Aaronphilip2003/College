#include <iostream>
using namespace std;
class Complex
{
    float real;
    float imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(float x, float y);
    void display();
    friend Complex operator+(Complex &a, Complex &b);
    Complex operator-(Complex &b)
    {
        Complex temp;
        temp.real = real - b.real;
        temp.imag = imag - b.imag;
        return temp;
    }
    friend Complex operator*(Complex &a, Complex &b);
};

Complex::Complex(float x, float y)
{
    real = x;
    imag = y;
}

Complex operator+(Complex &ca, Complex &cb)
{
    Complex temp;
    temp.real = ca.real + cb.real;
    temp.imag = ca.imag + cb.imag;
    return temp;
}

Complex operator*(Complex &ca, Complex &cb)
{
    Complex temp;
    temp.real = ca.real * cb.real;
    temp.imag = ca.imag * cb.imag;
    return temp;
}

void Complex::display()
{
    cout << real << " + " << imag << "i" << endl;
}

int main()
{
    Complex c1, c2, c3, c4, c5;
    c1 = Complex(2.5, 3.5);
    c2 = Complex(2.4, 3.6);
    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    c3.display();
    c4.display();
    c5.display();
    return 0;
}