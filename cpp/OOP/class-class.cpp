#include<iostream>
using namespace std;
namespace inherit{
    class A{
    public:
        A(){
            cout<<"A constructor"<<endl;
        }
        ~A(){
            cout<<"A destructor"<<endl;
        }
    };
    class B:public A{
    public:
        B(){
            cout<<"B constructor"<<endl;
        }
        ~B(){
            cout<<"B destructor"<<endl;
        }
    };
    int main(){
        B b;
        return 0;
    }

}

namespace inherit_compose_1{
    class A{
    public:
        A(){
            cout<<"A constructor"<<endl;
        }
        ~A(){
            cout<<"A destructor"<<endl;
        }
    };
    class C{
    public:
        C(){
            cout<<"C constructor"<<endl;
        }
        ~C(){
            cout<<"C destructor"<<endl;
        }
    };
    class B:public A{
    public:
        C c;
        B(){
            cout<<"B constructor"<<endl;
        }
        ~B(){
            cout<<"B destructor"<<endl;
        }
    };
}
namespace inherit_compose_2{
    class C{
    public:
        C(){
            cout<<"C constructor"<<endl;
        }
        ~C(){
            cout<<"C destructor"<<endl;
        }
    };
    
    class A{
    public:
        C c;
        A(){
            cout<<"A constructor"<<endl;
        }
        ~A(){
            cout<<"A destructor"<<endl;
        }
    };

    class B:public A{
    public:
        B(){
            cout<<"B constructor"<<endl;
        }
        ~B(){
            cout<<"B destructor"<<endl;
        }
    };
}
int main(){
    // inherit::B b; // 自行选择注释
    cout<<"-------------------"<<endl;
    // inherit_compose_1::B b2;
    cout<<"-------------------"<<endl;
    inherit_compose_2::B b3;
    return 0;
}