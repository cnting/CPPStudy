#include "iostream"

using namespace std;

class Person {
public:
    void showClassName() {
        cout << "this is Person" << endl;
    }

    void showPersonAge() {
        //这里使用了this指针，this指针是空的，所以报错
        cout << "age = " << m_Age << endl;
    }

    int m_Age;

};

void test1() {
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();  //这里报错
}

int main() {
    test1();
}