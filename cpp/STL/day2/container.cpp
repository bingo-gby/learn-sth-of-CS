# include<iostream>
# include<list>
# include<array>
# include<deque>
# include<queue>
# include<stack>
# include<vector>
using namespace std;

int main(){
    list<int> l;    // 跳转看list实现、
    vector<int> v;
    // for(int i=0; i<10; i++){
    //     v.push_back(i);
    // }
    // for(auto i=v.begin(); i!=v.end(); i+=2){
    //     cout<<*i<<endl;
    // }
    iterator_traits<vector<int>::iterator>::difference_type a;
    array<int, 10> arr;
    deque<int> d;  // 跳转看deque实现
    queue<int> q;  // 跳转看queue实现
    stack<int> s;  // 跳转看stack实现
}