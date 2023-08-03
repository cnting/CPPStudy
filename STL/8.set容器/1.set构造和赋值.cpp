#include "iostream"
#include "set"

using namespace std;

/**
 * set会自动排序
 */
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

    //拷贝构造
    set<int> s2(s1);

    //赋值
    set<int> s3;
    s3 = s2;
}

int main() {
    test1();
}