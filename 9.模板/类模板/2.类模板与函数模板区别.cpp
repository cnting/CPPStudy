#include <iostream>

using namespace std;
//区别：
//1.类模板没有自动类型推导的使用方式
//2.类模板在模板参数列表中可以有默认参数

template<class NameType, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name:" << m_Name << ",age:" << m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test1() {
    //1.类目标没有自动类型推导的使用方式
//    Person p1("Tom", 10);   //报错
    Person<string,int> p1("Tom", 10);
    p1.showPerson();

    //在模板的参数列表里指定了默认参数
    Person<string> p2 ("ssss",222);
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
