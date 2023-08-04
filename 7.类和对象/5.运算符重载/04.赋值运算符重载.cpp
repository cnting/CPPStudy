#include "iostream"

using namespace std;

/**
 * C++编译器至少给一个类添加4个函数
 * 1.默认构造
 * 2.默认析构
 * 3.默认拷贝构造
 * 4.赋值运算符 operator=，对属性进行值拷贝
 *
 * 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
 */
class Person {
public:
    Person(int age) {
        m_Age = new int(age);
    }

    ~Person() {
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
    Person &operator=(Person &p) {
        //应该先判断是否有属性在堆区，如果有，先释放干净，然后再深拷贝
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);
        return *this;
    }

    int *m_Age;
};

void test1() {
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;

    cout << "p1年龄：" << *p1.m_Age << endl;
    cout << "p2年龄：" << *p2.m_Age << endl;
    cout << "p3年龄：" << *p3.m_Age << endl;
}


int main() {
    test1();
}
