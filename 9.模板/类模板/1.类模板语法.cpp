#include <iostream>

using namespace std;

template<class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name:" << m_Name << ",age:" << m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test1() {
    Person<string, int> p1("Tom", 10);
    p1.showPerson();
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
