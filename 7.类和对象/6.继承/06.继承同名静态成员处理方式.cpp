#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        m_A = 100;
    }
    static void func()
    {
        cout << "Base-func()" << endl;
    }
    static int m_A;
};
// static 类内声明，类外初始化
int Base1::m_A = 100;

class Son1 : public Base1
{
public:
    Son1()
    {
        m_A = 200;
    }
    static void func()
    {
        cout << "Son-func()" << endl;
    }
    static int m_A;
};
int Son1::m_A = 200;

// 同名成员属性的处理方式
void test1()
{
    Son1 son;
    cout << "Son 下 m_A = " << son.m_A << endl;
    // 如果通过子类对象 访问到父类中同名成员，需要加作用域
    cout << "Base 下 m_A = " << son.Base1::m_A << endl;

    cout << "通过类名访问:" << endl;
    cout << "Son 下 m_A = " << Son1::m_A << endl;
    // 第一个::代表通过类名方式访问
    // 第二个::代表访问父类作用域下的
    cout << "Base 下 m_A = " << Son1::Base1::m_A << endl;
}

// 同名成员函数的处理方式
void test2()
{
    Son1 son;
    cout << "通过对象访问" << endl;
    // 直接调用，调用的是子类中的
    son.func();
    // 调用父类中同名方法
    son.Base1::func();

    cout << "通过类名访问" << endl;
    Son1::func();
    Son1::Base1::func();
}

int main(int argc, char const *argv[])
{
//     test1();
    test2();
    return 0;
}
