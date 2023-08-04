#include <iostream>

using namespace std;

//1.普通函数调用可以发生隐式类型转换
//2.函数模板用自动类型推导，不可以发生隐式类型转换
//3.函数模板用显式指定类型，可以发生隐式类型转换

//普通函数
int myAdd1(int a, int b) {
    return a + b;
}

template<class T>
T myAdd2(T a, T b) {
    return a + b;
}

void test1() {
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd1(a, b) << endl;
    cout << myAdd1(a, c) << endl;

    //自动类型推导，不会发生隐式类型转换
//    cout << myAdd2(a, c) << endl;  //报错
    //显式指定类型，会发生隐式类型转换
    cout << myAdd2<int>(a, c) << endl;

}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
