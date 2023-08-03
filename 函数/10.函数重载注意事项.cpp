#include <iostream>

using namespace std;

//函数重载的注意事项：
//1.引用作为重载的条件
void func(int &a) {
    cout << "func(int &a)调用" << endl;
}

void func(const int &a) {
    cout << "func(const int &a)调用" << endl;
}

//2.函数重载碰到默认参数
void func2(int a) {
    cout << "func2(int a)" << endl;
}
void func2(int a,int b = 10) {
    cout << "func2(int a,int b)" << endl;
}


int main(int argc, char const *argv[]) {
    int a = 10;
    func(a); //会调用func(int &a)
    func(10); //会调用func(const int &a)

//    func2(10);   //报错
}
