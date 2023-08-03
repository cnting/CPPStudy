#include "iostream"

using namespace std;

/**
 * 常函数：
 * 1. 成员函数后加const后我们称这个函数为常函数
 * 2. 常函数内不可以修改成员属性
 * 3. 成员属性声明时加关键字mutable后，在常函数中依然可以修改
 *
 * 常对象：
 * 1. 声明对象前加const称该对象为常对象
 * 2. 常对象只能调用常函数
 *
 */
class Person {
public:
    //this指针的本质是指针常量，指针的指向不可以修改
    //this指针其实就是 Person * const this;
    //在函数后加const后，修饰的是this指针，也就是 const Person * const this;
    void showPerson() const {
//        m_A = 100;  //报错
        m_B = 200;   //不报错
    }

    void func(){
        m_A = 100;
    }

    int m_A;
    mutable int m_B;  //特殊变量，即使在常函数中，也可以修改这个值

};

void test1() {
    Person p;
    p.showPerson();
}

void test2() {
    //常对象
    const Person p{};
//    p.m_A = 200;  //报错
    p.m_B = 200;

    //常对象只能调用常函数
    p.showPerson();
    //常对象不能调用普通成员函数，因为普通成员函数可以修改属性
//    p.func();     //报错

}

int main() {
    test1();
}