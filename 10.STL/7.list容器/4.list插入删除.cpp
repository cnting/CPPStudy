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
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    print(l1);

    //尾删
    l1.pop_back();
    print(l1);

    //头删
    l1.pop_front();
    print(l1);

    //插入
    list<int>::iterator it = l1.begin();
    it++;
    l1.insert(it, 1000);
    print(l1);

    //删除
    it = l1.begin();
    l1.erase(it);
    print(l1);

    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    l1.remove(10000);
    print(l1);

    //在尾部插入1
    l1.back() = 1;
    print(l1);
}


int main() {
    test1();
}