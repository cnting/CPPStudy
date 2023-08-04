#include <iostream>

using namespace std;

//占位参数：只填数量类型
void func(int a, int) {
    cout << "this is func" << endl;
}

//占位参数还可以有默认参数
void func2(int a, int = 10) {
    cout << "this is func" << endl;
}

int main(int argc, char const *argv[]) {
    func(10, 20);
    func2(20);
    return 0;
}
