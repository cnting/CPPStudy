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
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(2, 20));


    if (m.empty()) {
        cout << "m为空" << endl;
    } else {
        cout << "m不为空" << endl;
        cout << "个数：" << m.size() << endl;
    }

    map<int, int> m2;
    m2.insert(pair<int, int>(100, 10));
    m2.insert(pair<int, int>(200, 30));

    cout << "交换前"<< endl;
    print(m);
    print(m2);

    m.swap(m2);

    cout << "交换后"<< endl;
    print(m);
    print(m2);
}

int main() {
    test1();
};