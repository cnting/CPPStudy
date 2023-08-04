#include <iostream>

using namespace std;

void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

//声明一个模板，T是通用数据类型
template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void test1() {
    int a = 10;
    int b = 20;
//    swapInt(a, b);
//    cout << "a=" << a << ",b=" << b << endl;

    //使用函数模板，有两种使用方式
    //1.自动类型推导
    mySwap(a, b);
    cout << "a=" << a << ",b=" << b << endl;

    //2.显式指定类型
    mySwap<int>(a,b);
    cout << "a=" << a << ",b=" << b << endl;
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
