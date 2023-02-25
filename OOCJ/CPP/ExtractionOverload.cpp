#include <iostream>
using namespace std;

class Complex
{
public:
    float real;
    float imag;
    friend istream &operator>>(istream &in, Complex &c);
    friend ostream &operator<<(ostream &out, const Complex &c);
};

istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter real and imaginary parts: ";
    in >> c.real >> c.imag;
    return in;
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.real << " + " << c.imag << "i";
    return out;
}

int main()
{
    Complex c1;
    cin >> c1;
    cout << "Complex number is: " << c1 << endl;
    return 0;
}
