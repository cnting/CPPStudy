#include "iostream"

using namespace std;

class Phone {
public:
    Phone(string name) {
        cout << "Phone构造" << endl;
        m_PName = name;
    }
    ~Phone(){
        cout << "Phone析构" << endl;
    }

    string m_PName;
};

class Person {
public:
    Person(string name, string pName) : m_Name(name), m_Phone(pName) {
        cout << "Person构造" << endl;
    }
    ~Person(){
        cout << "Person析构" << endl;
    }

    string m_Name;
    Phone m_Phone;
};

void test1() {
    Person p("张三", "apple");

    cout << p.m_Name << "," << p.m_Phone.m_PName << endl;
}


int main() {
    test1();
}