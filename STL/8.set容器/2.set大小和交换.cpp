#include "iostream"
#include "set"

using namespace std;

void print(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    print(s1);

    if (s1.empty()) {
        cout << "s1为空" << endl;
    } else {
        cout << "s1不为空" << endl;
        cout << "s1个数:" << s1.size() << endl;
    }
}

//交换
void test2() {
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);

    set<int> s2;
    s2.insert(100);
    s2.insert(400);
    s2.insert(300);

    print(s1);
    print(s2);

    cout << "交换后" << endl;
    s1.swap(s2);

    print(s1);
    print(s2);
}

int main() {
    test1();
    test2();
}