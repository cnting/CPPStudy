#include "iostream"

using namespace std;

int main() {
    int a = 10;
    //定义指针的语法：数据类型 * 指针变量名
    int *p;
    //让指针记录变量a的地址
    p = &a;

    cout << "a的地址：" << &a << endl;
    cout << "指针p:" << p << endl;

    //使用指针
    //可以通过解引用的方式来找到指针指向的内存
    //解引用：指针前加*
    *p = 1000;

    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
}
