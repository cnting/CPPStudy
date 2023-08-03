#include "iostream"

using namespace std;

class Person {
public:
    //1.所有对象都共享同一份数据
    //2.在编译阶段分配内存
    //3.类内声明，类外初始化
    static int m_A;

    //静态成员变量也是有访问权限的
private:
    static int m_B;
};


int Person::m_A = 100;
int Person::m_B = 200;

void test1() {
    Person p;
    cout << p.m_A << endl;

    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}

void test2() {
    //静态成员变量有两种访问方式
    //1.通过对象访问
    Person p;
    cout << p.m_A << endl;

    //2.通过类访问
    cout << Person::m_A << endl;
//    cout << Person::m_B << endl;  //报错
}

int main() {
//    test1();
    test2();
}