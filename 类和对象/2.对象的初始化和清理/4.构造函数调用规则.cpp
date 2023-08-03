#include "iostream"

using namespace std;

/**
 * 默认情况下，C++至少给一个类添加3个函数
 * 1. 默认构造函数（无参，函数体为空）
 * 2. 默认析构函数（无参，函数体为空）
 * 3. 默认拷贝构造函数，对属性进行值拷贝
 *
 * 构造函数调用规则：
 * 1. 如果用户定义有参构造函数，C++不会提供默认无参构造，但会提供默认拷贝构造
 * 2. 如果用户定义拷贝构造，C++不会再提供其他构造函数
 */
class Person {
public:

    Person() {
        cout << "Person无参构造调用" << endl;
    }

    Person(int a) {
        age = a;
        cout << "Person有参构造调用" << endl;
    }

    //拷贝构造函数
    Person(const Person &p) {
        age = p.age;
        cout << "Person拷贝构造调用" << endl;
    }

    ~Person() {
        cout << "Person析构函数调用" << endl;
    }

    int age;
};

void test1() {
    Person p1(20);
    //把拷贝构造注释掉，编译器也会生成拷贝构造函数
    Person p2(p1);

    cout << p2.age << endl;
}

void test2() {
    Person p(10);
    Person p2(p);
}

int main() {
    test1();
}