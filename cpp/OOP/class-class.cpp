#include<iostream>
using namespace std;
class A{
public:
    A(){
        cout<<"A constructor"<<endl;
    }
    ~A(){
        cout<<"A destructor"<<endl;
    }
};
class B{
public:
    B(){
        cout<<"B constructor"<<endl;
    }
    ~B(){
        cout<<"B destructor"<<endl;
    }
    A a;
};
int main(){
    B b;
    return 0;
}