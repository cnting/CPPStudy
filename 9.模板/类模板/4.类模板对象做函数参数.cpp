#include <iostream>

using namespace std;

//类模板对象做函数参数：
template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "姓名:" << this->m_Name << ",年龄:" << this->m_Age << endl;

    }

    T1 m_Name;
    T2 m_Age;

};

//1.指定传入类型(常用)
void printPerson1(Person<string, int> &p) {
    p.showPerson();
}

void test1() {
    Person<string, int> p("孙悟空", 100);
    printPerson1(p);
}

//2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
    //看推出的是什么数据类型
    cout << "T1的类型为:" << typeid(T1).name() << endl;
    cout << "T2的类型为:" << typeid(T2).name() << endl;
}

void test2() {
    Person<string, int> p("猪八戒", 90);
    printPerson2(p);
}

//3.整个类模板化
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T的类型:" << typeid(T).name() << endl;
}

void test3() {
    Person<string, int> p("唐僧", 30);
    printPerson3(p);
}

int main(int argc, char const *argv[]) {
    test1();
    test2();
    test3();
    return 0;
}
