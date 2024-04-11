# include<iostream>
using namespace std;

int main(){
    is_void<int>::value; // false
    is_integral<int>::value; // true
    
    is_class<int>::value; // false
    is_union<int>::value; // false
    is_enum<int>::value; // false
    is_pod<int>::value; // true


}