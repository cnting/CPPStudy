#include "iostream"

using namespace std;

int main() {
    int a = 10;

    //引用相当于给a起了别名，叫b，两者指向同一个内存
    //引用语法：数据类型 &别名 = 原名
    int &b = a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    b = 100;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

}
