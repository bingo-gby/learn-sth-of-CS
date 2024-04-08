#include<iostream>
#include<cstring>
#include<hashtable.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int main(){
    // hashtable
    // 也可以跳转看hash实现 
    hashtable<string, string, hash<string>, _Identity<string>, equal_to<string>> ht; // 点击跳转到hashtable.h，查看hashtable实现
    hashtable<int, int, hash<int>, _Identity<int>, equal_to<int>> ht2;  // 可以看hash(int)和hash(string)的实现

    
    unordered_map<int, int> m;

}