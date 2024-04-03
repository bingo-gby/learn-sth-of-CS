#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;



int main(){
   allocator<int> alloc;   // 点击跳转到allocator.h，查看alloctor实现
   vector<int> v ; // 跳转到vector，看vector参数
   vector<string,__gnu_cxx::__pool_alloc<string>> v1; // 跳转到pool_allocator.h，查看pool_allocator实现
}


