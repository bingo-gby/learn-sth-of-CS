#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

int main(){

    // ostream_iterator 使用
    std::vector<int> myvector;
    for (int i = 0; i < 10; i++)
    {
       myvector.push_back(i*10);
    }
    // 类似于 cout << 0 << "," << 10 << ","  so on
    std::ostream_iterator<int> out_it(std::cout, ","); 
    
    std::copy(myvector.begin(), myvector.end(), out_it); // 0,10,20,30,40,50,60,70,80,90,
    std::cout<<std::endl;

    // istream_iterator 使用
    double value1, value2;
    std::cout << "Please, insert two values: ";
    std::istream_iterator<double> eos;              // end-of-stream iterator
    std::istream_iterator<double> iit (std::cin);   // stdin iterator，一创建就会直接read输入的值
    if (iit!=eos) value1=*iit;   // 就是存储输入的值
    ++iit;
    if (iit!=eos) value2=*iit;
    std::cout << value1 << "*" << value2 << "=" << value1*value2 << std::endl;

    // 比较复杂的例子 istream_iterator
    std::vector<int> c;
    std::istream_iterator<int> iit(std::cin),eos;              // end-of-stream iterator
    std::copy(iit, eos, std::inserter(c,c.begin()));  // 从cin中读取数据，插入到c中
    // 利用ctrl+z结束输入
    for(auto i : c)
        std::cout<<i<<" ";
    return 0;
}


