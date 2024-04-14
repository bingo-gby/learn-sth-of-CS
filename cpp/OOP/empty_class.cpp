#include<iostream>
using namespace std;

class A{
public:
    void use(){
        cout<<"A类的使用"<<endl;
    }
};

int main(){
    A a;
    cout<<sizeof(a)<<endl;  // 1
    return 0;
}