#include<iostream>
using namespace std;
namespace example1{
    class F{
    public:
        F(int _a,int _b):a(_a),b(_b){}
        operator double(){
            return (double)(a/b);
        }
    private:
        int a;
        int b;
    };
    int main(){
        F f(3,2);
        double a = 4+f;
        cout<<a<<endl;
        return 0;
    }
}
namespace example2{
    class A{
    public:
        A(int num):num(num){}
    private:
        int num;
    };

    int main(){
        A a = 3;
        return 0;
    }
}

int main(){
    example1::main();
    example2::main();
    return 0;
}