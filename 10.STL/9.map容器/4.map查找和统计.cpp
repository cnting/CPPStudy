#include "iostream"
#include "map"

using namespace std;

void print(map<int, int> &m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

void test1() {
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));

    //查找
    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end()) {
        cout << "找到了 key=" << pos->first << " value=" << pos->second << endl;
    } else {
        cout << "未找到" << endl;
    }

    //统计
    int num = m.count(3);
    cout << num << endl;
}

int main() {
    test1();
};