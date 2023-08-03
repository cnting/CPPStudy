#include "iostream"
#include "list"

using namespace std;

void print(const list<int> &l) {
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    print(l1);

    list<int> l2;
    l2 = l1;
    print(l2);

    list<int> l3;
    l3.assign(l1.begin(), l1.end());
    print(l3);

    list<int> l4;
    l4.assign(10, 100);
    print(l4);
}

void test2() {
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    list<int> l2;
    l2.assign(10, 100);

    cout << "交换前:" << endl;
    print(l1);
    print(l2);
    cout << "交换后:" << endl;
    l1.swap(l2);
    print(l1);
    print(l2);
}

int main() {
    test1();
    test2();
}