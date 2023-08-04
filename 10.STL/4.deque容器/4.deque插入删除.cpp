#include "iostream"
#include "deque"

using namespace std;

void print(const deque<int> &d) {
    for (auto it = d.begin(); it < d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    print(d1);

    //尾删
    d1.pop_back();
    print(d1);
    //头删
    d1.pop_front();
    print(d1);
}

void test2() {
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    print(d1);
    d1.insert(d1.begin(), 1000);
    d1.insert(d1.begin(), 2, 10000);
    print(d1);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    //1 2 3 10000 10000 1000 200 100 10 20
    d1.insert(d1.begin(), d2.begin(), d2.end());
    print(d1);
}

void test3() {
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    deque<int>::iterator  it = d1.begin();
    it++;
    //200 10 20
    d1.erase(it);

    //清空
    d1.erase(d1.begin(), d1.end());
    d1.clear();
}

int main() {
//    test1();
//    test2();
    test3();
}