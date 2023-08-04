#include "iostream"

using namespace std;

//1.引用必须要初始化
//2.引用一旦初始化后，就不可以更改
int main() {
    int a = 10;
//    int &b;    //会报错
    int &b = a;

    int c = 20;
    b = c;   //这是赋值操作，而不是更改引用

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
}
