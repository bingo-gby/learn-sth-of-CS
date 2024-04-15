<!-- TOC -->

- [day2](#day2)
  - [分配器](#分配器)
  - [List](#list)
- [Iterator traits](#iterator-traits)
- [vector](#vector)
- [Array](#array)
- [forward\_list](#forward_list)
- [deque queue 和 stack](#deque-queue-和-stack)

<!-- /TOC -->
# day2
## 分配器
分配器基本不会自己用到，但是需要了解一下，包括效率等；  
开辟内存：底层是operator new函数，该函数调用了malloc  
查看allocator.h的实现，见 allocator.cpp,不断去跳转基类，发现底层就是调用**operator new**来开辟内存,下为source code
```
pointer allocate(size_type __n, const void* = static_cast<const void*>(0))
{
if (__n > this->max_size())
    std::__throw_bad_alloc();

#if __cpp_aligned_new
if (alignof(_Tp) > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
    {
    std::align_val_t __al = std::align_val_t(alignof(_Tp));
    return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp), __al));
    }
#endif
return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
}
```
通常vector等容器有默认第二个参数，就是默认allocator，查看源码，如下
```
template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
class vector : protected _Vector_base<_Tp, _Alloc>
```
存在问题，每malloc一次会产生over head（多余的内容，比如储存开辟空间大小），所以要尽量减少malloc的次数，要不然会开辟很大的内存（比实际需要储存的内存大的多）   
GNU2.9版本，所以内存里面是以链表形式存在（**其实也有可能课程中讲的是老版本，老版本的vector的第二个参数是alloc，不是allocator，新版本好像是一样的默认allocator**）  
GNU4.9版及之后是默认allocator，见上面src，之前的alloc是现版本的_pool_alloc,源码在 c++/ext/pool_allocator.h中，阅读发现是两级空间配置器，第一级是__pool_alloc，第二级是__pool_alloc_base，源码也比较简单，源码解析链接：[alloc源码解析](https://mp.weixin.qq.com/s/ea2plCwpxqsXfk6Pt9Brvg)。
## List
list是最具代表性的，所以先看list 双向链表  
主要考虑iterator，因为要重载i++(加个int参数)，和++i，因为list是非连续空间，所以要自定义 iterator类 ，源码阅读链接如下 [list源码解析](https://mp.weixin.qq.com/s?__biz=MzkzMjQ5NTAyMg==&mid=2247483876&idx=1&sn=aba69eed274a6666695b50d0c92f759b&chksm=c25baa25f52c2333756381b72757ff8b95fdc836bac0e31c9deaf31dea660f8aba4ba1b89311#rd)。  
# Iterator traits
traits意为萃取剂，就是萃取特性，以iterator_traits为例，萃取iterator的特性。换言之就是算法通过traits，要知道iterator的五个特性：  
1. iterator_category(指移动性质，比如只能++，只能--，是否可以任意访问，还是只能顺序访问，比如链表只能ite++，不可以ite+=2,vector就可以i+=2) 
2. difference_type(两个iter之间的距离用什么来表示，比如vector::iterator可以直接相减，但是list就不行，因为list不能随机访问)
3. value_type(就是iterator的类型，比如str int 等)
4. reference 和 pointer（这两个在STL库中没怎么使用过）  

但是上面的五个特性，在list_iterator中都有的，那traits在哪？且只有class才能typedef,那如果不是class呢，如native pointer（普通指针），这时就需要去使用iterator_traits。所以iterator_traits作用就是用来分辨是 **class** 还是 **non-class**。所以写个iterator_traits 进行特化即可（针对指针进行特化）
```
template <class T>
struct iterator_traits{
    typedef typename I::value_type value_type;
}

template <class T>
struct iterator_traits<T*>{
    typedef T value_type;
}

template <class T>
struct iterator_traits<const T*>{
    typedef T value_type;
}
```
之后直接拿value_type就ok了，注意输入const T*的时候，输出还是T，因为得到是对象类型，其余的特性同样特化。  
# vector
vector相对来说比较简单，就是动态数组，数组用完之后，自动扩充。通常2倍扩充。通过三个指针来控制
```
pointer _M_start;
pointer _M_finish;
pointer _M_end_of_storage;
```
每一次扩容需要调用多次拷贝构造函数
# Array
静态数组,封装成container，便于使用算法，但实际上无ctor和dtor（构造函数和析构函数）
# forward_list
单向链表，具体跟前面的双向环状链表大同小异。
# deque queue 和 stack
deque是双向队列..是底层container，是以不连续空间假装连续空间。现在是设计每个buffer是512 bytes，元素个数就看 512/元素大小  
queue和stack内含deque即可，但是这两个不可以随意访问，deque可以随意访问，实际使用感觉跟vector没啥区别...queue和stack也不允许遍历，因此也没有Iterator。












