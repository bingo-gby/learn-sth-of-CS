# 标准库STL
标准库以header files形式呈现，全部头文件封装于namespace std 中，so  
`using namespace std;` or `using std::cout`(单独使用std某个函数)  
六大组件：容器 分配器 算法 迭代器 适配器 仿函数
# 容器
序列容器 Array Vector Deque List Forward-List  
关联式容器 set/Multiset Map/Multimap  （红黑树）  
无序容器： unordered_set  unordered_map（hash_table）

写测试程序中有个好习惯：多写namespace 如 namespace j1 namespace j2，且为了便于找变量，**变量通常不做缩进处理，就好找变量**（写测试程序中）,但是我自己尝试了下 感觉一般般  
find函数是循序查找，deque是分段连续。。
# 分配器allocator
通常容器都会有默认分配器
# OOP GP
oop为面向对象，都放在一个class里面。gp是data和methods分开，就是模板
algorithm其实就是比container里面的大小
# 源代码阅读基础
操作符重载 和 模板  
类模板 函数模板 具体代码看template.cpp,为泛化；  
特化就是针对特定类型，有独特的做法，称为特化；  
同样针对部分参数进行特化，称为偏特化
# summary
day1主要讲了一些基础概念，可以理解为后面的basic
