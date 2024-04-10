# Algorithms
container的Iterator 必须要能回答Algorithms的所有提问，才可以搭配算法的操作。算法其实是 function template(函数模板)，其余组件是class template。

# Iterator Category
就是迭代器怎么走；主要分为以下几种：
1. random_access_iterator_tag
2. bidirectional_iterator_tag  双向
3. farward_iterator_tag 单向
4. input_iterator_tag
5. output_iterator_tag
分别有继承关系，3继承4 2继承3 1继承2.
```
///  Marking input iterators.
struct input_iterator_tag { };

///  Marking output iterators.
struct output_iterator_tag { };

/// Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag { };

/// Bidirectional iterators support a superset of forward iterator
/// operations.
struct bidirectional_iterator_tag : public forward_iterator_tag { };

/// Random-access iterators support a superset of bidirectional
/// iterator operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag { };
```
可以使用typeid(str).name() 输出类型，**基本output iterators 就是cout中(这个后续会展开讲，这里也不是很明白)**。

# iterator_category 对算法的影响
例如需要根据iterator_category来计算 迭代器之间的distance（需要获得迭代器类型）
specialization 特化 generalization 泛化 refinement 强化  
iterator_category对于算法的效率影响较大..  
具体就看函数的源码，这里不展开细讲...

# 算法源码部分剖析
见algo.cpp,学习其用法.注意函数模板没有特化，只能重载
1. accumulate函数  
accumulate函数就是累计，可以累加、累减
2. for_each 函数  
   ```for_each(I first,I last, Function F)```
   对于迭代器内的每个元素都经过F函数。
3. replace replace_if replace_copy函数  
   ```void replace(_ForwardIterator __first, _ForwardIterator __last,const _Tp& __old_value, const _Tp& __new_value)```  
   replace就是新值取代旧值；  
   replace_if 就是添加个判别式，将符合判别式的值用新值取代，通常给if都是给条件判别式；  
   repalce_copy 需要提供新的起点，然后把符合old_value改为new value 放到新区间，不符合的就放原值到新区间；  

4. count, count_if函数  
   count就是计数，count_if就是计算符合条件的数目；
   有些容器带有同名函数：关联式容器都带 count 和 count_if
   > 理解为关联式容器便于查找，所以函数重载一下，效率更快  
5. find 和 find_if 函数  
    返回第一个符合条件的iterator，同理关联式容器均有同名函数。因为泛化的find和find_if函数都是循序式查找
6. sort函数  
   只有list 和 forward_list有自己的sort函数，因为 最原始的sort函数需要Random_Access_Iterator
7. rbegin() 和 rend()  
    r意味着reverse，rbegin意味着reverse后的begin(),举例说明：
    ```
    vector<int>v{1,2,3,4,5}
    ```
    begin() 指向1，end()指向null，rbegin()指向5，rend()指向null
8. binary_search函数  
   二分查找法，需要有序序列，调用的lower_bound函数，对应的有个upper_bound函数，举例说明：       
   lower_bound插入位置为大于等于的第一个位置，upper_bound为大于等于的最后一个位置，所以用lower 和 upper来区分，意味着边界。

# 仿函数 functors
仿函数实际是个类，通过重载(),模拟函数的使用，有多种：
1. using default comparison
2. using function as comp,传入函数名
3. using object as comp  

通常**自写仿函数**如果想嵌入到STL中，需要继承 binary_function(二元)或是 unary_function(一元)，继承了之后就会有一些typedef，就会有一些 result_type等之类的，没有继承的话，就之后没有被适配器(Adapter)修饰的机会。

# 适配器 Adapter
核心在于改造...有 Function Adapter 、 Iterator Adapter、Container Adapter...

## 容器适配器
 stack和 queue比较简单，不多讲...

## 函数适配器
### bind2nd
顾名思义，绑定第二个参数，看源码：
```
template<typename _Operation, typename _Tp>
inline binder2nd<_Operation>
bind2nd(const _Operation& __fn, const _Tp& __x)
{
    typedef typename _Operation::second_argument_type _Arg2_type;
    return binder2nd<_Operation>(__fn, _Arg2_type(__x));  // 将x转为 _Arg2_type，要不然会出错
} 
```
就是把第二个参数绑定为自己提供的值  
一般都是一个类，一个辅助函数（类binder2nd，函数bind2nd）,对外提供的就是辅助函数。    
同时有个值得注意的地方，上面源码中 typedef后有个typename，这是为了告知编译器```_Operation::second_argument_type``` 这个是个数据类型，让编译器去操作，要么编译器要去自行推导，复杂一点；  
现在貌似都被bind取代，bind源码较为复杂，可自行去看。
### not1
自行阅读源码，就是取反
### bind
bind是c++11中新提出的，取代之前的bind1st bind2nd等函数。  
#### 绑定函数or 函数对象
```
auto my = bind(minus<int>(), placeholders::_1, 10);
cout<<my(5)<<endl; // 5-10=-5
```
上为绑定函数对象参数（与函数参数同理），前面用auto进行类型自动推导。placeholders::_1意味着占位符，代表传入的第一个参数，10代表第二个参数...     
#### 绑定成员函数
```
class myDivide{
   public:
      int multiply(int a, int b){
            return a*b;
      }   
};

// 用bind绑定成员函数
myDivide my1;
auto myDiv = bind(&myDivide::multiply,placeholders::_1,placeholders::_2,placeholders::_3);
cout<<myDiv(my1,10,20)<<endl; // 20*10=200
```
可以看出，**绑定跟类相关的东西，第一个参数必须是一个object**，上面&可写可不写，反正输出的需要是成员函数地址
#### 绑定成员
绑定成员时需要输入成员地址，需要加&，见 adapter.cpp。

## 迭代器适配器
### reverse_iterator
以rbegin()为例，```reverse_iterator
      rbegin() _GLIBCXX_NOEXCEPT
      { return reverse_iterator(end()); }```  
      再看reverse_iterator的实现，traits对应的associated type 是一样的。不一样的是取值，++,--等操作，见下：
```
// current就是对应的正向迭代器
reference operator*() const{
	_Iterator __tmp = current;
	return *--__tmp;
}

reverse_iterator& operator++(){
	--current;
	return *this;
}
```

### inserter
copy函数直接copy会影响后面空间的值，用inserter就会直接开辟新空间（**理解为把赋值操作重载为插入操作**）
```
vector<int> v2{1,2,3,4,5};
vector<int> v3{6,7,8,9,10};
copy(v2.begin(),v2.end(),inserter(v3,v3.begin())); // 1 2 3 4 5 6 7 8 9 10
```
inserter需要两个参数，一个是container，一个是迭代器；
```
insert_iterator& operator=(const typename _Container::value_type& __value){
	iter = container->insert(iter, __value);
	++iter;
	return *this;
}
```
看源码实现就是重载=为insert。  

## X适配器
X意味着未知，通常就是 ostream_iterator 和 istream_iterator，见 X_adapter.cpp。  
### ostream_iterator
```
// ostream_iterator 使用
std::vector<int> myvector;
for (int i = 0; i < 10; i++)
{
   myvector.push_back(i*10);
}
std::ostream_iterator<int> out_it(std::cout, ",");
std::copy(myvector.begin(), myvector.end(), out_it); // 0,10,20,30,40,50,60,70,80,90,
return 0;
```
我们看copy函数的源码，只贴出核心部分，first为初始迭代器，end为最后迭代器，result为要移动到的位置：
```
while(first!=end){
   *result=*first;
   ++result;
   ++first;
}
```
out_it 先调用构造函数，记录传进去的值,就是 _M_stream是cout对象的地址，_M_string是","。
```
ostream_iterator(ostream_type& __s, const _CharT* __c)
: _M_stream(&__s), _M_string(__c)  { }
```
接着看*和 = 重载，_value为传进去的值
```
*_M_stream << __value;  // 直接cout value
if (_M_string) *_M_stream << _M_string;  // 如果_M_string不为空，就输出_M_string
return *this;
```
这样上面输出就是 ```0,10,20,30,40,50,60,70,80,90,``` 了。

### istream_iterator
这个就是绑定cin，绑定到键盘的输入。值得注意的是,cin一绑定就存储输入的值;
```
#include<iostream>
#include<iterator>

int main() {
    std::cout << "Enter a double: ";
    std::istream_iterator<double> iit(std::cin);
    std::cout << "You entered: " << *iit << std::endl; // 输出读取的值  
    return 0;
}
```
比较复杂一点的一个例子:
```
std::vector<int> c;
std::istream_iterator<int> iit(std::cin),eos;              // end-of-stream iterator
std::copy(iit, eos, std::inserter(c,c.begin()));  // 从cin中读取数据，插入到c中
// 利用ctrl+z结束输入
for(auto i : c)
   std::cout<<i<<" ";
return 0;
```




   