#include "iostream"

using namespace std;

/**
 * 静态成员函数：
 * 1.所有对象共享同一个函数
 * 2.静态成员函数只能访问静态成员变量
 */

class Person {
public:
    static void func() {
        cout << "static void func()" << endl;
        m_A = 200;
//        m_B = 200;  //无法访问
    }
    static int m_A;
    int m_B;

private:
    static void func2(){
        cout << "static void func2()" << endl;
    }
};

int Person::m_A = 100;

void test1() {
    //1.通过对象访问
    Person p;
    p.func();

    //2.通过类访问
    Person::func();
//    Person::func2();  //无法访问
}


int main() {
    test1();
}