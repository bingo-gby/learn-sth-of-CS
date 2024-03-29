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




