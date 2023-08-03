#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void myPrint(int val) {
    cout << val << endl;
}

void test1() {
    vector<Person> v;
    v.push_back(Person("aaa", 10));
    v.push_back(Person("bbb", 20));
    v.push_back(Person("ccc", 30));
    v.push_back(Person("ddd", 40));
    v.push_back(Person("eee", 50));


    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
//        cout << "姓名：" << (*it).m_Name << ",年龄：" << (*it).m_Age << endl;
        cout << "姓名：" << it->m_Name << ",年龄：" << it->m_Age << endl;
    }
}

void test2() {
    //存放的是指针
    vector<Person *> v;
    Person p1 = Person("aaa", 10);
    Person p2 = Person("bbb", 20);
    Person p3 = Person("ccc", 30);
    Person p4 = Person("ddd", 40);
    Person p5 = Person("eee", 50);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it < v.end(); it++) {
        cout << "s姓名：" << (*it)->m_Name << ",年龄：" << (*it)->m_Age << endl;
    }
}

int main() {
    test1();
    test2();
}