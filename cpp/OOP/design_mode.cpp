#include<iostream>
#include<vector>
using namespace std;
// 组合模式
namespace composite_mode{
    class Component{
    public:
        virtual void add(Component* c){};
        virtual int size(){};
    };
    // file和composite都是component的子类
    class file:public Component{
      
    };
    class Composite:public Component{
    public:
        vector<Component*> children;
        void add(Component* c){
            cout<<"Composite add"<<endl;
            children.push_back(c);
        }
        int size(){
            return children.size();
        }
    };
    int main(){
        Component* leaf1=new file();
        Component* leaf2=new file();
        Component* composite1=new Composite();
        composite1->add(leaf1);
        composite1->add(leaf2);
        Component* composite2 = new Composite();
        // composite2下有一个目录composite1，composite1下有两个文件leaf1和leaf2
        composite2->add(composite1);  
        std::cout<<composite2->size()<<std::endl; //1
        std::cout<<composite1->size()<<std::endl; // 2
        return 0;
    }
}
// 原型模式
namespace prototype_mode{
    
// 声明一个抽象产品类，定义克隆方法
    class Product {
    public:
        virtual ~Product() = default;
        virtual Product* clone() const = 0; // 纯虚克隆函数
        virtual void use() = 0; // 纯虚使用函数
    };

    // 具体产品类，实现产品类
    class ConcreteProductA : public Product {
    public:
        ~ConcreteProductA() override = default;

        // 实现克隆方法，创建产品的深拷贝
        Product* clone() const override {
            return new ConcreteProductA(*this);
        }

        void use() {
            std::cout << "Using product A..." << std::endl;
        }
    };
    // 客户端代码
    int main() {
        // 创建一个产品A的实例
        ConcreteProductA original;
        original.use();

        // 克隆原始产品，创建一个新的产品实例
        Product* clone = original.clone();
        clone->use();

        // 释放克隆产品的内存
        delete clone;
        return 0;
    }
}
int main(){
    composite_mode::main();
    cout<<"----------------"<<endl;
    prototype_mode::main();
    return 0;
}

