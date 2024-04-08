#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(){
    set<int> s;
    multiset<int> ms;

    map<int, int> m;
    multimap<int, string> mm;

    cout<<m[2]<<endl; // 0  虽然没找到，但是会插入一个默认值0
    cout<<m[1]<<endl; // 0
    cout<<m.size()<<endl; // 2
}