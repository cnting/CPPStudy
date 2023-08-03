#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

/**
 * 统计元素个数
 */

class Greater20 {
public:
    bool operator()(int val) {
        return val > 20;
    }
};

//统计内置数据类型
void test1() {
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    int num = count_if(v.begin(), v.end(), Greater20());
    cout << num << endl;
}

class Person {
public:
    Person(string n, int a) {
        this->m_Name = n;
        this->m_Age = a;
    }

    //重载==，find才知道如何对比Person类型
    bool operator==(const Person &p) {
        return this->m_Age == p.m_Age;
    }

    string m_Name;
    int m_Age;
};

class Greater20Age {
public:
    bool operator()(const Person &p) {
        return p.m_Age>=20;
    }
};

//统计自定义数据类型
void test2() {
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 20);
    Person p4("ddd", 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    int num = count_if(v.begin(), v.end(), Greater20Age());
    cout << num << endl;
}

int main() {
//    test1();
    test2();
}
