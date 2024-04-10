#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

int main(){

    std::vector<int> v {1, 2, 3, 4, 5};

    // accumulate() 累计函数
    int ans = std::accumulate(v.begin(), v.end(), 0); // 15  
    std::cout<<ans<<std::endl;
    int ans2 = std::accumulate(v.begin(), v.end(), 0, std::minus<int>());  // -15
    std::cout<<ans2<<std::endl;

    // for_each() 函数
    for_each(v.begin(), v.end(), [](int i){std::cout<<i<<" ";}); // 1 2 3 4 5  用lambda表达式输出

    // replace()  replace_if  replace_copy函数
    std::replace(v.begin(), v.end(), 3, 33); // 1 2 33 4 5
    std::for_each(v.begin(),v.end(),[](int i){std::cout<<i<<" ";});

    std::replace_if(v.begin(), v.end(), [](int i){return i>3;}, 44); // 1 2 44 44 44
    std::for_each(v.begin(),v.end(),[](int i){std::cout<<i<<" ";});

    std::vector<int> v1(v);
    std::replace_copy(v.begin(),v.end(),v1.begin(),44, 55);
    std::for_each(v1.begin(),v1.end(),[](int i){std::cout<<i<<" ";}); // 1 2 55 55 55




    
}