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

    //查找
    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end()) {
        cout << "找到元素：" << *pos << endl;
    } else {
        cout << "没有找到" << endl;
    }

    //统计
    int num = s1.count(30);
    cout << "统计30的个数：" << num << endl;
}

int main() {
    test1();
}