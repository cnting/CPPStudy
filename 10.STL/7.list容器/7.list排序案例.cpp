#include "iostream"
#include "list"

using namespace std;

class Person {
public:
    Person(string name, int age, int height) {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

bool comparePerson(Person &p1, Person &p2) {
    if (p1.m_Age == p2.m_Age) {
        return p1.m_Height > p2.m_Height;
    }
    return p1.m_Age < p2.m_Age;
}

void test1() {
    list<Person> l1;
    l1.push_back(Person("刘备", 35, 170));
    l1.push_back(Person("曹操", 45, 180));
    l1.push_back(Person("孙权", 40, 170));
    l1.push_back(Person("赵云", 25, 190));
    l1.push_back(Person("张飞", 35, 175));

    for (list<Person>::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "姓名:" << it->m_Name << ",年龄：" << it->m_Age << ",身高：" << it->m_Height << endl;
    }

    cout << "------------" << endl;
    l1.sort(comparePerson);

    for (list<Person>::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "姓名:" << it->m_Name << ",年龄：" << it->m_Age << ",身高：" << it->m_Height << endl;
    }
}


int main() {
    test1();
}