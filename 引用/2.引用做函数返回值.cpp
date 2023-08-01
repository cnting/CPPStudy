#include <iostream>
using namespace std;

// 1.不要返回局部变量的引用
int &test1()
{
    int a = 10; // 局部变量放栈区
    return a;
}
// 2.函数调用可以作为左值
int &test2()
{
    static int a = 10; // 静态变量放全局区，在程序执行后释放
    return a;
}
int main(int argc, char const *argv[])
{
    // int &ref = test1();
    // cout << ref << endl; // 会报内存泄漏

    int &ref2 = test2();
    cout << ref2 << endl;

    test2() = 1000;
    cout << ref2 << endl;

    return 0;
}
