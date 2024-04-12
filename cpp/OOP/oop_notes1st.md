# OOP notes 1st
关于面向对象高级编程的笔记第一讲

## 1. 头文件.h 和源文件 .cpp
头文件声明，源文件实现，源文件包含头文件和 标准库的某些文件。包含头文件时：
>#include<a.h> 包含标准库头文件用尖括号<>   
>#include"a.h" 包含自建头文件用双引号" "  

头文件中需要避免被重复包含：
```
// 写在文件最开头
#ifndef _A_
#define _A_

...

#endif
```
上面代码含义为 if \_A_ 没有被 define，就define一下，然后包含；第二次包含时，发现已经define了,就不会进入下面的代码，就不会被重复包含(ps: **A通常为文件名**，且#ifndef要写在文件最开头)。  

## 2. without pointer class中layout
主要讲没有指针的class中的某些常用到的属性，例如构造函数，析构函数，inline关键字等...

### inline关键字
inline是对编译器的建议，通常简单点的函数都可以是inline，编译时进行内联，有点类似于宏。推荐inline关键字放在定义前。
### 数据访问
数据要写成private，尽量使用数据时，以接口的形式返回。
### 构造函数
构造函数尽量使用初始化来初始化初值（理解有两过程：初始化和赋值，尽量在初始化的时候就完成）
```
// 假如类名为complex,有两个member data
complex(double r,double i):re(r),im(i){}
```
构造函数可以重载，例如默认构造，有参构造，拷贝构造，c++中支持函数重载的原因是因为：  
>函数编译会对函数名进行修饰，取决于编译器 

函数重载有时也不能同时存在，例如：
```
// 这两个构造函数不能同时存在，要不然会导致歧义
complex(double r=0,double i=0):re(r),im(i){}
complex():re(0),im(0){}
```

1. 构造函数被放在private  
    就是不能为外界创建对象，只能在堆区创建对象；(单例模式)
    ```
    #include<iostream>
    using namespace std;

    class A{
    public:
        static A& getInstance(){
            static A instance;
            return instance;
        }
    private:
        A(){}
    };

    int main(){
        A& a = A::getInstance();
        return 0;
    }
    ```
2. 常量成员函数  
加const 修饰，不改变数据，只能放在()后，大括号前，如``` double real() const{return re;}```,如果放在跟double一起，就会存在歧义。并且 **常对象调用常函数**，反正根据常识来看，**不能常对象调用非常函数**。
3. friend 关键字  
   友元，可以自由访问private成员。
4. pass by reference  
   1. 拷贝构造函数必须传引用，如果传值，就会无限递归...
   2. 一般操作符重载 += -=都return by reference,因为原本的值会变。
### 操作符重载和临时对象
1. 例如```c2+=c1```，右边c1为传入的参数，作用在左边c2上，所以默认参数有个this，代表c2；  
2. += 可以连续赋值： ```c3+=c2+=c1```从右往左执行，且返回值需要为引用。  
3. +返回的需要是value，不能是reference；举例：  
   ```
    T operator +(const T& a,const T& b){...}
   ```
   因为 int a = b+c,返回的是一个临时对象，所以只能返回值，临时对象脱离作用域就会自动destory。
4. 临时对象是 `typename()`
5. 重载<<:
    ```
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
    ```
    [重载<<代码示例](example.cpp)
    考虑几个点：
    >1.ostream& os前要不要加const(这里为cout)：不可以，加了说明os不能改，往os丢东西其实就是在改os状态  
    >2.连串的输出，所以return by reference
## 3. with pointer class中layout
上面讲了类中没指针的class(以complex为例)，这里讲下带指针的class，以string为典型例子. 但是string标准库较为复杂，选择自己实现：[my_string](my_string.cpp)
### 1. 拷贝构造 赋值
如果含有指针，应该要重写拷贝构造和赋值函数，避免浅拷贝...，具体见[my_string.cpp](my_string.cpp)  
1. ```if(this == &s){return *this;  // 检测是否自我赋值}```:  
    该检测自我赋值必须有，要不然如果两个指针指向同一个对象，会直接delete掉，原本数据也delete掉了。
2. 重载<<输出string,该函数要写成非成员函数：
    >如果写成 成员函数，还需要类来调用，不符合常理，而且cout的位置也会发生变化，之前是```cout<<c```,之后是`c.operator<<(cout)`;如果要连续输出就是：`cout << str1 <<str2<<endl; 和 str2.operator<<(str1.operator<<(cout));`
    ```
    // 适配cout,写成非成员函数
    inline ostream& operator<<(ostream& os, const my_string& s){
        return os << s.get_c_str();
    }
    
    //写成成员函数
    inline ostream& operator<<(ostream& os){
        return os << this->get_c_str();
    }
    ```
### 2. 栈和堆
普通对象：作用域结束就自动析构；    
静态对象：作用域结束不析构，等程序结束，再析构，但是**超出作用域不能再使用了**；  
全局对象：程序结束再析构；
```
int a = 10;
int main(){
    {   
        static int b = 20;
        int c = 30;
    }
    cout<<a<<endl;
    cout<<b<<endl; // 无法使用
    cout<<c<<endl; // 无法使用
}
```
1. new 和 delete
new可以分解为以下3步,`complex* pc = new complex(1,2)`：
```
void* mem = operator new(sizeof(complex)); // 分配内存
pc = static_cast<int*>(mem); // 类型转换
pc->complex::complex(1,2);   // 构造函数
```
delete转换为两个动作：先调用析构函数，再释放内存。  
delete[] 调用多次析构函数，delete 只调用1次析构函数，所以 new[]一般就配合delete[]。








