#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class GreaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

//查找内置数据类型
void test1() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //查找是否有>5
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        cout << "不存在" << endl;
    } else {
        cout << "存在:" << *it << endl;
    }
}


class Person {
public:
    Person(string n, int a) {
        this->m_Name = n;
        this->m_Age = a;
    }

    string m_Name;
    int m_Age;
};

class Greater20Age {
public:
    bool operator()(const Person &p) {
        return p.m_Age > 20;
    }
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

    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20Age());
    if (it == v.end()) {
        cout << "不存在" << endl;
    } else {
        cout << "存在 " << it->m_Name << " " << it->m_Age << endl;
    }
}

void test3() {
    vector<string> v;
    v.push_back("aaa");
    v.push_back("bbb");
    v.push_back("ccc");
    v.push_back("ddd");

    //bind2nd()表示固定第二个参数
    //aaa相当于equal_to中的right，将集合中的所有元素都跟aaa比较
    vector<string>::iterator it = find_if(v.begin(), v.end(), bind2nd(equal_to<string>(), "aaa"));
    if (it == v.end()) {
        cout << "不存在" << endl;
    } else {
        cout << "存在 " << *it << endl;
    }
}

int main() {
//    test1();
//    test2();
    test3();
}
