#include "iostream"

using namespace std;

void sum(int count, ...) {
    va_list vp;
    //可变参数开始方法，count表示从哪里开始
    va_start(vp, count);

    //读出第一个变量
//    int number = va_arg(vp, int);
//    cout << number << endl;

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(vp, int);
    }
    //结尾
    va_end(vp);

    cout << sum << endl;
}

void test1() {
    sum(3, 1, 2, 10);
}

int main() {
    test1();
}
