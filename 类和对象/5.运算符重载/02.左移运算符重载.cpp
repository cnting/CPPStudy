#include "iostream"

using namespace std;

/**
 * 左移运算符重载，可以自定义输出内容
 */
class Person {
    friend ostream &operator<<(ostream &cout, Person &p);

public:
    Person(int a, int b) {
        m_A = a;
        m_B = b;
    }

private:
    //不会利用成员函数实现<<，因为无法实现 cout << p
//    void operator<<() {
//
//    }

    int m_A;
    int m_B;
};

//2.全局函数重载+号
ostream &operator<<(ostream &cout, Person &p) {
    cout << "m_A = " << p.m_A << "，m_B = " << p.m_B;
    return cout;
}

void test1() {
    Person p1(10, 10);
    cout << p1 << endl;

}

int main() {
    test1();
}
