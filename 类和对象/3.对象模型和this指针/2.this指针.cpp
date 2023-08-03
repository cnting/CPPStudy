#include "iostream"

using namespace std;

/**
* 每个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
 * 那么问题是：这一块代码是如何区分哪个对象调用自己的呢？
 * 答案是通过this指针，this指针指向被调用的成员函数所属的对象
 *
 * this指针用途：
 * 1. 当形参和成员变量同名时，可以用this指针来区分
 * 2. 在类的非静态成员函数中返回对象本身，可使用return *this;
*/
class Person {
public:
    Person(int age) {
        this->age = age;
    }

    //注意这里有&
    Person &PersonAddAge(Person &p) {
        this->age += p.age;
        return *this;
    }

    //注意这里没有&，会返回一个调用拷贝构造的新对象，所以每次返回的都是一个新的Person
    Person PersonAddAge1(Person &p) {
        this->age += p.age;
        return *this;
    }

    int age;
};


void test1() {
    Person p1(18);
    cout << p1.age << endl;
}

void test2() {
    Person p1(10);
    Person p2(10);
    p2.PersonAddAge(p1)
            .PersonAddAge(p1)
            .PersonAddAge(p1)
            .PersonAddAge(p1);
    //输出50
    cout << p2.age << endl;

    Person p3(10);
    p3.PersonAddAge1(p1)
            .PersonAddAge1(p1)
            .PersonAddAge1(p1)
            .PersonAddAge1(p1);
    //输出20
    cout << p3.age << endl;
}

int main() {
//    test1();
    test2();
}