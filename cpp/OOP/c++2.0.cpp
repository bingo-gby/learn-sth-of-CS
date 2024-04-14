#include<iostream>
using namespace std;
// 看编译器版本
namespace cpp_2{
    int main()
    {
        cout << __cplusplus << endl; // 201402
        return 0;
    }
}
namespace reference{
    int main()
    {
        int a = 10;
        int &b = a;
        cout << a << " " << b << endl; // 10 10
        b = 20;
        cout << a << " " << b << endl; // 20 20
        return 0;
    }

}

int main(){
    cpp_2::main();
    reference::main();
    return 0;
}
