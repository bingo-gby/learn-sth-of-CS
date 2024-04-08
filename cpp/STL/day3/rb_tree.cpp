#include<iostream>
#include<map>
using namespace std;

int main() {

    _Rb_tree<int, int, _Identity<int>, less<int>> t;
    cout<<t.size()<<endl; // 0
    cout<<t.empty()<<endl;// 1

    t._M_insert_unique(10);
    t._M_insert_unique(20);
    t._M_insert_unique(30);
    t._M_insert_unique(40);
    t._M_insert_unique(50);
    t._M_insert_unique(10);   // 10 already present

    cout<<t.size()<<endl; // 5
    cout<<t.empty()<<endl; // 0

    t._M_insert_equal(10);  // 10 can be inserted

    cout<<t.size()<<endl; // 6
    cout<<t.empty()<<endl; // 0

    // // 通过key找value
    auto it = t.find(10);
    cout<<*it<<endl; // 10

    return 0;
}