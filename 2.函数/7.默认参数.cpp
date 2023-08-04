#include <iostream>

using namespace std;

//可以设置默认值
int func1(int a, int b = 20, int c = 30) {
    return a + b + c;
}

//如果函数声明有默认参数，函数实现就不能有默认参数
int func2(int a, int b = 10);


int func2(int a, int b) {
    return a + b;
}

int main(int argc, char const *argv[]) {
    cout << func1(10, 20, 30) << endl;
    cout << func1(10, 40) << endl;

    cout << func2(10) << endl;
    return 0;
}
