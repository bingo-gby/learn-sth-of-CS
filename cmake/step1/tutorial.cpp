// 执行平方根函数
#include <iostream>
#include <cmath>

// argv[0]是程序名，argv[1]是输入的参数
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    double inputValue = std::stod(argv[1]);
    double outputValue = sqrt(inputValue);
    std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;

    return 0;
}   