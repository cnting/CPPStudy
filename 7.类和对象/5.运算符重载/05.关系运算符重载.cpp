#include "iostream"

using namespace std;

class Person {
public:
    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
    }

    bool operator==(Person &p) {
        return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
    }

    bool operator!=(Person &p) {
        return this->m_Name != p.m_Name || this->m_Age != p.m_Age;
    }

    string m_Name;
    int m_Age;
};

void test1() {
    Person p1("Tom", 18);
    Person p2("Tom", 18);

    if (p1 == p2) {
        cout << "相等" << endl;
    } else {
        cout << "不相等" << endl;
    }
    if (p1 != p2) {
        cout << "不相等" << endl;
    } else {
        cout << "相等" << endl;
    }
}


int main() {
    test1();
}
