# OOP notes 1st
关于面向对象高级编程的笔记第一讲

## 头文件.h 和源文件 .cpp
头文件声明，源文件实现，源文件包含头文件和 标准库的某些文件。包含头文件时：
>#include<a.h> 包含标准库头文件用尖括号<>   
>#include"a.h" 包含自建头文件用双引号" "  

头文件中需要避免被重复包含：
```
ifndef _A_
#define _A_

...

#endif
```
上面代码含义为 if __A__ 没有被 define，就define一下，然后包含；第二次包含时，发现已经define了,就不会进入下面的代码，就不会被重复包含(ps: **A通常为文件名**)。  

## class中layout
主要讲class中的某些常用到的属性，例如构造函数，析构函数，inline关键字等...

### inline关键字
inline是对编译器的建议，通常简单点的函数都可以是inline，编译时进行内联，有点类似于宏。
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



