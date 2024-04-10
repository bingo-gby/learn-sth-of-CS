#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyCompare{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};
int main(){
    vector<int> v {1, 2, 3, 4, 5};

    sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}