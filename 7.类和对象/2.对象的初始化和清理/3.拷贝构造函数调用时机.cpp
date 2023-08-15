#include "iostream"

using namespace std;

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

//拷贝构造调用时机通常有三种情况：
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test1() {
    Person p1(20);
    Person p2(p1);

    cout << p2.age << endl;
}

//2.值传递的方式给函数参数传值，会创建一个新对象
void doWork(Person p) {

}

void test2() {
    Person p;
    doWork(p);
}

//3.以值方式返回局部对象，所以会产生一个新对象
Person doWork2() {
    Person p1;
    return p1;
}

void test3() {
    Person p = doWork2();
}

int main() {
//    test1();
//    test2();
    test3();
}