#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>
#include <algorithm>
// array test
namespace j1{
    void test_array(){
        int size = 500000;
        std::cout<<"array test"<<std::endl;
        std::array<int, 500000> a;
        clock_t start = clock();
        for(int i = 0; i < 10; i++){
            a[i] = rand() ;
        }
        std::cout<<"放50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;\
        start = clock();
        std::sort(a.begin(),a.end());
        std::cout<<"排序50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;

        start = clock();
        // 二分查找一个数
        int target = rand();
        int* p = std::lower_bound(a.begin(),a.end(),target);
        std::cout<<"查找 "<<target<<" 花费时间"<<clock()-start<<"ms"<<std::endl;
    }
}

#include <vector>
// vector test
namespace j2{
    void test_vector(){
        std::cout<<"vector test"<<std::endl;
        int size = 500000;
        std::vector<int> v;
        clock_t start = clock();
        for(int i = 0; i < size; i++){
            v.push_back(rand());
        }
        std::cout<<"放50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        std::sort(v.begin(),v.end());
        std::cout<<"排序50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        // 二分查找一个数
        int target = rand();
        std::vector<int>::iterator p = std::lower_bound(v.begin(),v.end(),target);
        std::cout<<"查找 "<<target<<" 花费时间"<<clock()-start<<"ms"<<std::endl;
    }
}
#include <list>
namespace j3{
    void test_list(){
        std::cout<<"list test"<<std::endl;
        int size = 500000;
        std::list<int> l;
        clock_t start = clock();
        for(int i = 0; i < size; i++){
            l.push_back(rand());
        }
        std::cout<<"放50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        l.sort();
        std::cout<<"排序50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        // 二分查找一个数
        int target = rand();
        std::list<int>::iterator p = std::lower_bound(l.begin(),l.end(),target);
        std::cout<<"查找 "<<target<<" 花费时间"<<clock()-start<<"ms"<<std::endl;
    }
}
#include <deque>
namespace j4{
    void test_deque(){
        std::cout<<"deque test"<<std::endl;
        int size = 500000;
        std::deque<int> d;
        clock_t start = clock();
        for(int i = 0; i < size; i++){
            d.push_back(rand());
        }
        std::cout<<"放50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        std::sort(d.begin(),d.end());
        std::cout<<"排序50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        // 二分查找一个数
        int target = rand();
        std::deque<int>::iterator p = std::lower_bound(d.begin(),d.end(),target);
        std::cout<<"查找 "<<target<<" 花费时间"<<clock()-start<<"ms"<<std::endl;
    }
}
#include<forward_list>
namespace j5{
    void test_forward_list(){
        std::cout<<"forward_list test"<<std::endl;
        int size = 500000;
        std::forward_list<int> fl;
        clock_t start = clock();
        for(int i = 0; i < size; i++){
            fl.push_front(rand());
        }
        std::cout<<"放50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        fl.sort();
        std::cout<<"排序50w元素花费时间: "<<clock()-start<<"ms"<<std::endl;
        start = clock();
        // 二分查找一个数
        int target = rand();
        std::forward_list<int>::iterator p = std::lower_bound(fl.begin(),fl.end(),target);
        std::cout<<"查找 "<<target<<" 花费时间"<<clock()-start<<"ms"<<std::endl;
    }
}

int main(){
    j1::test_array();
    j2::test_vector();
    j3::test_list();
    j4::test_deque();
    j5::test_forward_list();
    // 其余的container 请自行测试。 主要就是让大家感受一下不同的container的性能差异
    return 0;
}

