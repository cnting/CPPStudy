#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

//查找内置数据类型
void test1() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //查找是否有5这个元素，不存在返回的是v.end()
    vector<int>::iterator it = find(v.begin(), v.end(), 50);
    if (it == v.end()) {
        cout << "不存在" << endl;
    } else {
        cout << "存在" << endl;
    }
}

class Person {
public:
    Person(string n, int a) {
        this->m_Name = n;
        this->m_Age = a;
    }

    //重载==，find才知道如何对比Person类型
    bool operator==(const Person &p) {
        return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
    }

    string m_Name;
    int m_Age;
};

//查找自定义数据类型
void test2() {
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person p("bbb",20);
    vector<Person>::iterator it = find(v.begin(), v.end(), p);
    if (it == v.end()) {
        cout << "不存在" << endl;
    } else {
        cout << "存在 " << it->m_Name << " " << it->m_Age << endl;
    }
}

int main() {
//    test1();
    test2();
}
