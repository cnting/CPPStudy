#include <iostream>

using namespace std;

class Base {
public:
    //因为父类虚函数的实现一般是没什么意义的，这时候可以用纯虚函数
    //当有了纯虚函数，这个类就是抽象类
    //抽象类特点：
    //1.无法实例化对象
    //2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base {
public:
    void func() {
        cout << "func函数" << endl;
    }
};

void test1() {
    Base *base = new Son;
    base->func();
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
