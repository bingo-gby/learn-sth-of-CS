#include<functional>
#include<iostream>
#include<string>
using namespace std;


// 结合种子和值，生成新的种子
template<typename T>
inline void hash_combine(size_t &seed, const T &val) {
    hash<T> hasher;
    seed ^= hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
inline void hash_value(size_t& seed,const T &val) {
    hash_combine(seed, val);
}

template<typename T, typename... Types>
inline void hash_value(size_t& seed, const T &val, const Types&... args) {
    hash_combine(seed, val);
    hash_value(seed, args...);
}

template<typename... Types>
inline size_t hash_value(const Types&... args) {
    size_t seed = 0;
    hash_value(seed, args...);
    return seed;
}
class Customer {
public:
    string name;
    int age;
};
class CustomerHash {
public:
    size_t operator()(const Customer& c) const {
        return hash_value(c.name, c.age);
    }
};
int main() {
    Customer c1{"nico", 31}, c2{"binyun", 20};
    CustomerHash ch;
    cout << ch(c1)<< endl;
    cout << ch(c2) << endl;
}
