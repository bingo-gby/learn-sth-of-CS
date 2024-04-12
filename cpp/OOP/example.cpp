#include<iostream>
using namespace std;

class complex{
public:
    complex(double r, double i) : real(r), imaginary(i) {}
    double real;
    double imaginary;
};
inline  ostream& operator<<( ostream& os, const complex& c)
{
    return os << "Real: " << c.real << " Imaginary: " << c.imaginary;
    
}

int main()
{
    complex c(1.0, 2.0);
    cout <<c << endl;
    
}