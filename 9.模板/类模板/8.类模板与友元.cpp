#include <iostream>

using namespace std;

template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
    cout << "类外实现 姓名:" << p.m_Name << ",年龄:" << p.m_Age << endl;
}

//通过全局函数打印Person信息
template<class T1, class T2>
class Person {
    //全局函数 类内实现
    friend void printPerson(Person<T1, T2> p) {
        cout << "姓名:" << p.m_Name << ",年龄:" << p.m_Age << endl;
    }

    //全局函数 类外实现
    friend void printPerson2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};


void test1() {
    Person<string, int> p("Tom", 20);
    printPerson(p);

    printPerson2(p);
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
