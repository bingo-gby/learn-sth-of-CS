#include<iostream>

// 平方根函数
double mysqrt(int x) {
    double res = 1.0;
    double eps = 1e-6;
    while (std::abs(res * res - x) > eps) {
        res = (res + x / res) / 2;
    }
    return res;
}