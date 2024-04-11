#include<iostream>
#include<tuple>
using namespace std;

int main(){
    auto it = make_tuple(1, 2, "nico");
    auto it2 = make_tuple(1,"nico");
    cout<<typeid(it).name()<<endl;
    cout<<typeid(it2).name()<<endl;
    cout<<get<0>(it)<<endl;
}