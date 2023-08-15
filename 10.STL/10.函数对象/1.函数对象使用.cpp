#include "iostream"

using namespace std;

/**
 * 函数对象（也叫仿函数）概念
 * 1.重载 函数调用操作符 的类，其对象常称为 函数对象
 * 2.函数对象 使用重载的 () 时，行为类似函数调用，也叫 仿函数
 * 3.函数对象（仿函数）是一个类，不是一个函数
 *
 * 函数对象使用
 * 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
 * 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
 * 3.函数对象可以作为参数传递
 */

class MyAdd {
public:
    int operator()(int v1, int v2) {
        return v1 + v2;
    }
};

//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test1() {
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint {
public:
    MyPrint() {
        this->m_Count = 0;
    }

    void operator()(string test) {
        m_Count++;
        cout << test << endl;
    }

    int m_Count;
};

void test2() {
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout << "myPrint调用的次数：" << myPrint.m_Count << endl;
}

//3.函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test) {
    mp(test);
}

void test3() {
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++");
}

int main() {
//    test1();
//    test2();
    test3();
}