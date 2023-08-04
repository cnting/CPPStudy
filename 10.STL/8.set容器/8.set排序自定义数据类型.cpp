#include "iostream"
#include "set"

using namespace std;

/**
 * 对于自定义数据类型，set必须指定排序规则才能插入数据
 */
class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class MyCompare {
public:
    //仿函数
    //第一个()表示要重载的符号，第二个()表示函数体的参数列表
    //不允许修改，所以用const修饰
    //避免拷贝构造，所以用引用传递
    bool operator()(const Person &v1, const Person &v2) {
        //按年龄降序
        return v1.m_Age > v2.m_Age;
    }
};

void test1() {
    //自定义数据类型，都会指定排序规则
    set<Person, MyCompare> s;
    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person>::iterator it = s.begin(); it != s.end(); it++) {
        cout << it->m_Name << " " << it->m_Age << endl;
    }
}

int main() {
    test1();
}