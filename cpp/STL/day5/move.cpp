#include <iostream>
#include <vector>

class Movable {
public:
    Movable() { std::cout << "默认构造" << std::endl; }
    Movable(const Movable& other) { std::cout << "拷贝构造" << std::endl; }
    Movable(Movable&& other) noexcept { std::cout << "移动构造" << std::endl; }
};

int main() {
    Movable a;
    std::vector<Movable> vec2;
    vec2.emplace_back(a);
    vec2.emplace_back(std::move(a));  //  避免再次调用a，因为a已经被移动，此时a的状态是不确定的

    std::cout<<vec2.size()<<std::endl;
    return 0;
}
