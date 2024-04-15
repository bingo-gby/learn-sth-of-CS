<!-- TOC -->

- [RB-tree](#rb-tree)
- [set multiset](#set-multiset)
- [map mutlimap](#map-mutlimap)
  - [map的\[\]](#map的)
- [hashtable](#hashtable)
- [unordered\_map unordered\_multimap unordered\_set unordered\_multiset](#unordered_map-unordered_multimap-unordered_set-unordered_multiset)

<!-- /TOC -->
# RB-tree
RB-tree是红黑树，是map和set的底层，会自动排序，红黑树是平衡二元搜索树，有利于insert和 search，平衡意味着左右子树深度差不大，便于寻找.rb_tree提供两种insert操作，insert_unique() 和 insert_equal(),前者插不重复的，后者插重复的  
rb_tree用三个参数：
1. node_count: 节点数目
2. rb_tree_node* header ： 根节点指针
3. Compare key_compare： compare规则
模板参数如下：
```
template<typename _Key, 
        typename _Val, 
        typename _KeyOfValue,
        typename _Compare, 
        typename _Alloc = allocator<_Val>>
class _Rb_tree
{
    。。。
}
```
第三个参数keyofValue指的是个函数，通过value提取出用来compare的key，一般红黑树节点是个复杂的struct，可以自定义函数来提取struct中的某个属性用来compare。
# set multiset
set和multiset value和key合二为一,insert操作分别用unique和equal，set不允许根据iterator去改数据，怎么实现的呢？  
```
typedef _Rb_tree<key_type, value_type, _Identity<value_type>,
        key_compare, _Key_alloc_type> _Rep_type;
_Rep_type _M_t;  
typedef typename _Rep_type::const_iterator	 iterator;
```
可以看出底层封装了个rb_tree，且iterator用的是rb_tree的const_iterator，所以不可更改...而且底层封装的Rb_tree的keyofValue用的还是 _Identity(**意味着key和value一样的值**)
# map mutlimap
map mutlimap同样以rb_tree为底层，但是它key和value不一样，看源码怎么实现的：
```
public:
    typedef _Key					key_type;
    typedef _Tp					mapped_type;
    typedef std::pair<const _Key, _Tp>		value_type;
    typedef _Compare					key_compare;
    typedef _Alloc					allocator_type;

typedef _Rb_tree<key_type, value_type, _Select1st<value_type>,
        key_compare, _Pair_alloc_type> _Rep_type;
```
从源码中可以看出，map是insert一个value_type(就是个pair)，然后从pair中选第一个元素作为key(_Select1st函数的作用)。同时map的key是不可变的，源码中可以看出是因为是 pair<**const _key**, _Tp>。

## map的[]
map的[]重载,会用二分法去查找key，如果没找到会插入一个对应key的默认值，如果是int，那就是0。如set-map.cpp中所示。


# hashtable
hashtable就是哈希表，是unordered_set/unordered_mutliset 和 unordered_map/unordered_mutlimap的底层。
object映射到一个int T,假如有M个可以放的地方，就放到 T%M上（余数），但是这样有可能会出现哈希碰撞。让其串起来（形成链表），链表比较短时，搜索速度还是很快。链表长时怎么办？  
>经验所得，当elements num > buckets num ,需要rehashing(重新打散)； 
>尽量采用buckets num 为质数，rehashing的方式就是 buckets num 两倍附近的质数，比如最开始是53，那么rehashing后就是97(按道理不是103吗？所以我估计不是严格按照的，估计是rehashing后的大小用一个array储存起来)
hashtable模板如下：
```
template<class _Val,  
         class _Key,  
         class _HashFcn,  
	     class _ExtractKey,  
         class _EqualKey,  
         class _Alloc>
```
五个参数，key value，以及哈希函数，抽取key的函数，判断key是否相等的函数...它的类成员有：
```
private:
    hasher                _M_hash;
    key_equal             _M_equals;
    _ExtractKey           _M_get_key;
    _Vector_type          _M_buckets;
    size_type             _M_num_elements;
```
vector存储的是指针，指向链表的头节点 
```
typedef vector<_Node*, _Nodeptr_Alloc> _Vector_type;
```
同时，我们知道，对于hashtable_iterator而言，iterator++到了链表尽头需要进入下一个bucket，所以看源码发现iterator实现：
通过两个成员来控制
```
_Node* _M_cur;     // 指向当前节点
_Hashtable* _M_ht; // 指向hash_table
```
看其实现：
```
iterator& operator++()
{
    const _Node* __old = _M_cur;
    _M_cur = _M_cur->_M_next;

    // 如果_M_cur为空，走到了链表尽头了
    if (!_M_cur)
{
    size_type __bucket = _M_ht->_M_bkt_num(__old->_M_val);  // 获得是第几个哈希桶
    while (!_M_cur && ++__bucket < _M_ht->_M_buckets.size()) // 不断遍历，直至找到非空的
    _M_cur = _M_ht->_M_buckets[__bucket];
}
    return *this;
}
```
同时hashtable中比较重要的有hashFunc，就是转为hashCode，阅读看其实现,在hash_table.cpp中跳转看，看hash(int) 和 hash(string)：
```
// hash(int)直接返回val
template<>						
struct hash<_Tp> : public __hash_base<size_t, _Tp>  
{                                                   
    size_t                                            
    operator()(_Tp __val) const noexcept              
    { return static_cast<size_t>(__val); }            
};
```
hashFunc算的越乱，就越不会哈希冲突...
# unordered_map unordered_multimap unordered_set unordered_multiset
以hashtable为底层实现...
 



