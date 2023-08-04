#include <iostream>

using namespace std;

//函数重载的满足条件：
//1.同一个作用域下
//2.函数名相同
//3.函数参数不同，或个数不同，或顺序不同
//4.注意：函数的返回值不可以作为函数重载的条件
void func() {
    cout << "func调用" << endl;
}

void func(int a) {
    cout << "func(int a)调用" << endl;
}

void func(double a) {
    cout << "func(double a)调用" << endl;
}

int main(int argc, char const *argv[]) {
    func();
    func(1);
    func(1.1);
}
