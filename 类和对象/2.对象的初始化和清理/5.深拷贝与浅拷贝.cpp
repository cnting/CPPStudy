#include "iostream"

using namespace std;

/**
 * 浅拷贝：简单的赋值拷贝操作。
 * 深拷贝：在堆区重新申请空间，进行拷贝操作
 *
 * 注意：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
 */
class Person {
public:

    Person() {
        cout << "Person无参构造调用" << endl;
    }

    Person(int a, int height) {
        m_Age = a;
        m_Height = new int(height);
        cout << "Person有参构造调用" << endl;
    }

    //如果利用编译器提供的拷贝构造函数，会做浅拷贝，会导致m_Height指针重复释放报错
    //所以重写拷贝构造，实现深拷贝
    Person(const Person &p) {
        cout << "Person拷贝构造调用" << endl;
        m_Age = p.m_Age;
        //重新在堆区创建一块内存
        m_Height = new int(*p.m_Height);
    }

    ~Person() {
        if (m_Height != NULL) {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height;
};

void test1() {
    Person p1(20, 160);
    cout << "p1年龄：" << p1.m_Age << " 身高:" << *p1.m_Height << endl;

    Person p2(p1);
    cout << "p2年龄：" << p2.m_Age << " 身高:" << *p2.m_Height << endl;

}


int main() {
    test1();
}