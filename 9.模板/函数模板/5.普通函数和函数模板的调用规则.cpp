#include <iostream>

using namespace std;

/**
 * 调用规则：
 * 1.如果函数模板和普通函数都可以实现，优先调用普通函数
 * 2.可以通过 空模板参数列表 来强制调用函数模板
 * 3.函数模板也可以发生重载
 * 4.如果函数模板可以产生更好的匹配，优先调用函数模板
 *
 * 第一点的原因：c++编译时，会将myPrint模板函数生成具体的类型（比如说int），
 * 这时候如果发现已经有定义int类型的myPrint()，就不会再生成
 */

void myPrint(int a, int b) {
    cout << "调用普通函数" << endl;
}

template<class T>
void myPrint(T a, T b) {
    cout << "调用模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
    cout << "调用重载的模板" << endl;
}

void test1() {
    int a = 10;
    int b = 20;
    //1.调用了普通函数
    myPrint(a, b);

    //2.通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);

    //3.函数模板也可以重载
    myPrint(a, b, 100);

    //4.如果函数模板可以产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
