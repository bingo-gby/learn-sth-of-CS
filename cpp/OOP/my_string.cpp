#ifndef _MY_STRING_
#define _MY_STRING_

#include<iostream>
#include<cstring>
using namespace std;

class my_string{
public:
    my_string(const char* s=0);  // 默认构造函数
    my_string(const my_string& s); // 拷贝构造函数
    my_string& operator=(const my_string& s); // 赋值操作符
    ~my_string(); // 析构函数
    inline ostream& operator<<(ostream& os){
        return os << this->get_c_str();
    }
    char* get_c_str() const { return m_data; } // 获取字符串
private:
    char* m_data;
};
inline my_string::my_string(const char* s){
    if(s){
        m_data = new char[strlen(s) + 1];
        strcpy(m_data, s);
    }else{
        m_data = new char[1];
        *m_data = '\0'; // string的结束符
    }
}

inline my_string::my_string(const my_string& s){
    m_data = new char[strlen(s.m_data) + 1];
    strcpy(m_data, s.m_data);
}

inline my_string& my_string::operator=(const my_string& s){
    if(this == &s){
        return *this;  // 检测是否自我赋值
    }
    delete[] m_data;  // 释放原有的内存资源
    m_data = new char[strlen(s.m_data) + 1]; // 重新开辟空间
    strcpy(m_data, s.m_data);
    return *this;
}

inline my_string::~my_string(){
    delete[] m_data;
}

// 适配cout
inline ostream& operator<<(ostream& os, const my_string& s){
    return os << s.get_c_str();
}

int main(){
    my_string str1("Hello world");
    my_string str2("binyun");
    
    cout << str1 <<str2<<endl;
 
    str1.operator<<(cout);
    str2.operator<<(cout);
    str2.operator<<(str1.operator<<(cout)); // 先输出str1，再输出str2
    return 0;
}

#endif