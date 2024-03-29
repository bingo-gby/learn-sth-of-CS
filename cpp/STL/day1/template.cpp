#include <iostream>
// 模板泛化
// 函数模板，调用时编译器会自动推导类型
class A {
    public:
        A(int a) : a(a) {}
        bool operator<(const A& rhs) const {
            return a < rhs.a;
        }
        int get() const {
            return a;
        }
    private:
        int a;
};
namespace j4{
    template <typename T>
    const T& min(const T& a, const T& b) {
        return a < b ? a : b;
    }
}
// 类模板，用于定义复数类，为int float double等类型提供复数类
namespace j5{
    template <typename T>
    class complex{
        public:
            complex(T a=0, T b=0) : re(a), im(b) {}
            T real() const { return re; }
            T imag() const { return im; }
        private:
            T re, im;
    };
}
// 特化，争对特定类型特化
namespace j5{
    template <typename T>
    class special{
        public:
            special(T a) : a(a) {}
            void print() {
                std::cout << "普通模板类" << std::endl;
            }
        private:
            T a;
    };
    // 特化
    template <>
    class special<int>{
        public:
            special(int a) : a(a) {}
            void print() {
                std::cout << "int特化模板类" << std::endl;
            }
        private:
            int a;
    };
}

// 偏特化，对模板类的部分参数进行特化
namespace j6{
    template <typename T1,typename T2>
    class A{
        public:
            A(T1 a, T2 b) : a(a), b(b) {}
            void print() {
                std::cout << "普通模板类" << std::endl;
            }
        private:
            T1 a;
            T2 b;
    };
    // 偏特化,对T2进行特化，为int做特殊处理
    template <typename T>
    class A<T, int>{
        public:
            A(T a, int b) : a(a), b(b) {}
            void print() {
                std::cout << "int特化模板类" << std::endl;
            }
        private:
            T a;
            int b;
    };

}
int main(){
    A a(1), b(2);
    std::cout << j4::min(a, b).get() << std::endl; //1

    // 复数类模板
    j5::complex<int> c1;
    std::cout << c1.real() << " " << c1.imag() << std::endl;
    j5::complex<float> c2(1.1, 2.2);
    std::cout << c2.real() << " " << c2.imag() << std::endl;
    j5::complex<double> c3(1.1, 2.2);
    std::cout << c3.real() << " " << c3.imag() << std::endl;

    // 特化
    j5::special<int> s1(1);
    s1.print(); //int特化模板类
    j5::special<float> s2(1.1);
    s2.print(); //普通模板类

    // 偏特化
    j6::A<int, int> a1(1, 2);
    a1.print(); //int偏特化模板类
    j6::A<int, float> a2(1, 2.2);
    a2.print(); //普通模板类

    return 0;
}


