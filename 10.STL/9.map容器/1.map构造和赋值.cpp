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
    print(m);

    //拷贝构造
    map<int,int> m2(m);

    //赋值
    map<int,int> m3;
    m3 = m2;
}

int main() {
    test1();
};