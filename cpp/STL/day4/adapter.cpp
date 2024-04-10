#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using  namespace std;

int main(){
    vector<int> v{1,2,3,4,5};
    cout<< count_if(v.begin(),v.end(),bind2nd(less<int>(),40))<<endl;  // 数小于40的个数
    cout<<count_if(v.begin(),v.end(),not1(bind2nd(less<int>(),40)))<<endl; // 数大于40的个数,加了个not1，取否定
    
    // bind函数的用法
    auto my = bind(minus<int>(), placeholders::_1, 10);
    cout<<my(5)<<endl; // 5-10=-5

    class myDivide{
        public:
            int multiply(int a, int b){
                return a*b;
            }  
            int num;
    };

    // 用bind绑定成员函数
    myDivide my1{10};
    auto myDiv = bind(myDivide::multiply,placeholders::_1,placeholders::_2,placeholders::_3);
    cout<<myDiv(my1,10,20)<<endl; // 20*10=200

    // 绑定成员
    auto myDiv1 = bind(&myDivide::num,placeholders::_1);
    // 这个就不需要给参数，返回的是my1的num
    cout<<myDiv1(my1)<<endl; // 10

    // 迭代器适配器
    // 看reverse_iterator
    vector<int> v1{1,2,3,4,5};
    sort(v1.rbegin(),v1.rend());  // 5 4 3 2 1，逆序从小到大排列
    for(auto i:v1){
        cout<<i<<" ";
    }

    // 迭代器适配器 inserter
    vector<int> v2{1,2,3,4,5};
    vector<int> v3{6,7,8,9,10};
    copy(v2.begin(),v2.end(),inserter(v3,v3.begin())); // 1 2 3 4 5 6 7 8 9 10
    return 0;
}
