#include<iostream>
using namespace std;

int a = 10;
int main(){
    {   
        static int b = 20;
        int c = 30;
    }
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl; 
}