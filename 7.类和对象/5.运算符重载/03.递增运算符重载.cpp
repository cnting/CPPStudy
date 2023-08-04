#include "iostream"

using namespace std;

/**
 * 通过重载递增运算符，自己实现整型变量
 */

class MyInteger {
    friend ostream &operator<<(ostream &cout, MyInteger p);

public:
    MyInteger() {
        m_Num = 0;
    }

    //重载前置++运算符
    //返回引用是为了一直对一个数据进行递增
    MyInteger &operator++() {
        ++m_Num;
        return *this;
    }

    //重载后置++运算符
    //这个int是占位参数，用于区分前置和后置递增
    //要返回值，因为temp是局部变量，函数执行完就释放了，如果返回引用会导致内存泄漏
     MyInteger operator++(int) {
        MyInteger temp = *this;
        ++m_Num;
        return temp;
    }

private:
    int m_Num;
};

ostream &operator<<(ostream &cout, MyInteger p) {
    cout << p.m_Num;
    return cout;
}

void test1() {
    MyInteger num;
    cout << num << endl;
    cout << ++(++num) << endl;
}

void test2() {
    MyInteger num;
    cout << (num++) << endl;
    cout << num << endl;
}

int main() {
//    test1();
    test2();
}
