#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<array>
#include<forward_list>
#include<algorithm>
using namespace std;

template<typename T>
void displayCategory(T t){
    typename iterator_traits<T>::iterator_category category;
    cout<<typeid(category).name()<<endl;  // typeid() 返回类型的名称
}
int main(){
    displayCategory(vector<int>::iterator());  // Random Access Iterator
    displayCategory(list<int>::iterator());    // Bidirectional Iterator
    displayCategory(set<int>::iterator());     // Bidirectional Iterator
    displayCategory(map<int, int>::iterator()); // Bidirectional Iterator
    displayCategory(array<int, 5>::iterator()); // Random Access Iterator
    displayCategory(forward_list<int>::iterator()); // Forward Iterator

    displayCategory(istreambuf_iterator<int>()); // Input Iterator
    displayCategory(ostreambuf_iterator<int>(cout, "")); // Output Iterator 这代码貌似存在问题，但是无所谓了，只是想说明有这个类型

    // 跳转 distance() 函数，求迭代器之间的距离
    distance(vector<int>::iterator(), vector<int>::iterator()); // Random Access Iterator
    sort(vector<int>::iterator(), vector<int>::iterator()); // Random Access Iterator
    return 0;
}