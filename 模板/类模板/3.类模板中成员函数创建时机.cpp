#include <iostream>

using namespace std;
//类模板中成员函数与普通类中成员函数创建时机的区别：
//1.普通类中成员函数一开始就可以创建
//2.类模板中成员函数在调用时才创建

class Person1 {
public:
    void showPerson1() {
        cout << "Person1 show" << endl;
    }
};

class Person2 {
public:
    void showPerson2() {
        cout << "Person2 show" << endl;
    }
};

template<class T>
class MyClass {
public:
    T obj;


    void fun1() {
        obj.showPerson1();
    }

    //如果下面m.fun2()是注释的，会编译成功，因为这个方法目前没调用，是不会创建的
    //如果下面m.fun2()取消注释，这里会报错
    void fun2() {
        obj.showPerson2();
    }
};

void test1(){
    MyClass<Person1> m;
    m.fun1();
//    m.fun2();  //报错
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
