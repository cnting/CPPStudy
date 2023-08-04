#include <iostream>

using namespace std;

//模板局限性:
//模板不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

template<class T>
bool myCompare(T &a, T &b) {
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

//利用具体化Person的版本实现代码，具体化优先调用
template<>
bool myCompare(Person &a, Person &b) {
    if (a.m_Name == b.m_Name && a.m_Age == b.m_Age) {
        return true;
    } else {
        return false;
    }
}

void test1() {
    int a = 10;
    int b = 20;
    cout << myCompare(a, b) << endl;
}

void test2() {
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    cout << "Person对比：" << myCompare(p1, p2) << endl;//编译报错
}

int main(int argc, char const *argv[]) {
    test1();
    test2();
    return 0;
}
