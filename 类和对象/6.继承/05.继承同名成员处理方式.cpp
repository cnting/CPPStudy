#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base-func()" << endl;
    }
    void func(int a)
    {
        cout << "Base-func(int)" << endl;
    }
    int m_A;
};

class Son1 : public Base1
{
public:
    Son1()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son-func()" << endl;
    }
    int m_A;
};
// 同名成员属性的处理方式
void test1()
{
    Son1 son;
    cout << "Son 下 m_A = " << son.m_A << endl;
    // 如果通过子类对象 访问到父类中同名成员，需要加作用域
    cout << "Base 下 m_A = " << son.Base1::m_A << endl;
}

// 同名成员函数的处理方式
void test2()
{
    Son1 son;
    // 直接调用，调用的是子类中的
    son.func();
    // 调用父类中同名方法
    son.Base1::func();

    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类的同名成员函数
    // 也就是Base.func()和Base.func(int)都隐藏掉
    // 如果想访问，需要加作用域
    son.Base1::func(100);
}

int main(int argc, char const *argv[])
{
//     test1();
    test2();
    return 0;
}
