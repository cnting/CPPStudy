#include "iostream"

using namespace std;

class Person {

};

class Person1 {
public:
    //非静态成员变量，属于类的对象上
    int m_A;
};

class Person2 {
public:
    //非静态成员变量，属于类的对象上
    int m_A;
    //静态成员变量，不属于类对象上
    static int m_B;

    //非静态成员函数，也不属于类对象上
    void func() {

    }

    //静态成员函数，也不属于类对象上
    static void func2() {

    }
};

int Person2::m_B = 100;

void test1() {
    Person p;
    //空对象占用内存空间：1
    //C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "size of p = " << sizeof(p) << endl;
}

void test2() {
    Person1 p;
    //4
    cout << "size of p = " << sizeof(p) << endl;
}

void test3() {
    Person2 p;
    //4
    cout << "size of p = " << sizeof(p) << endl;
}

int main() {
//    test1();
//    test2();
    test3();
}