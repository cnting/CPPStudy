#include "iostream"

using namespace std;

int *func() {
    //为什么要将数据存堆区？
    //因为栈区数据在程序执行完（比如方法执行完）自动释放的，如果想自己管理释放，就要将数据开辟到堆区

    //利用new关键字，将数据开辟到堆区，返回的是地址，所以可以用指针存这个地址
    //指针本质也是局部变量，存放在栈上，指针保存的数据存放在堆区
    return new int(10);
}

int main() {
    int *p = func();
    cout << *p << endl;
}
