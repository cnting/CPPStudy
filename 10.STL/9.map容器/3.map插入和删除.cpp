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
    //插入
    //第一种
    m.insert(pair<int, int>(1, 10));
    //第二种
    m.insert(make_pair(2, 20));
    //第三种(不推荐)
    m.insert(map<int, int>::value_type(3, 30));
    //第四种(不建议)
    m[4] = 40;

    //这么写会导致插入一个m[5]=0，所以不建议用，可以用[]方式来遍历
    cout << m[5] << endl;

    print(m);

    //删除
    m.erase(m.begin());
    print(m);

    //按key删除
    m.erase(3);
    print(m);

    //清空
    m.clear();
}

int main() {
    test1();
};