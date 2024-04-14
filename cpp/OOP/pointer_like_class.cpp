#include<iostream>
using namespace std;

// 自己写的指针
namespace pointer_class{
    template<typename T>
    class my_pointer{
    public:
        my_pointer(T* ptr):ptr(ptr){}
        T& operator*() const {
            return *ptr;
        }
        T* operator ->(){
            return ptr;
        }
    private:
        T* ptr;
    };
    class A{
    public:
        A(int val):val(val){}
        void use(){
            cout<<"A类的使用"<<endl;
        }
    private:
        int val;
    };
    int main(){
        my_pointer<A> mp(new A(10));
        A a1(*mp);  // 拷贝构造
        mp->use();
        return 0;
    }       
}



int main(){
    pointer_class::main();
}
