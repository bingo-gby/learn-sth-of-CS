#include<iostream>
using namespace std;

class complex
{
    private:
        int real;
        int imag;
    public:
        complex(int r=0, int i=0)
        {
            real = r;
            imag = i;
        }
      double realPart() 
      {
          return real;
      }
      double imagPart() 
      {
          return imag;
      }
};

int main()
{
    
}