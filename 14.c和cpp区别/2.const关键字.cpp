#include "string"
#include "iostream"
using namespace std;

class Student {
public:
    void print() const {
//        name = "1234";  //常函数里改变量会报错
    }

    string name;
};

/**
 * 使用场景
 */
void test1() {
    //1.修饰变量不可变
    const int num1 = 1;

    //2.修饰指针：指针常量、常量指针
    int num2 = 1;
    const int *p1 = &num2;  //常量指针，不能改值
    int *const p2 = &num2;  //指针常量，不能改引用

    //3.在拷贝构造函数、运算符重载、方法后面(常函数)，禁止改变成员变量
    Student();
}

/**
 * c和c++的区别:
 * c里const是一个伪命题，可以通过指针去操作，因为它是在编译器检测
 * c++里不光在编译器做处理，还在运行时做了处理
 */
void test2() {
    const int num1 = 1;
    int *ptr = const_cast<int *>(&num1);
    *ptr = 2;
    cout << num1 << endl;  //1
    cout << *ptr << endl;  //2
}

int main() {
    test2();
}