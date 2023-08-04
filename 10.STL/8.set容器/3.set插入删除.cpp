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

    //删除
    s1.erase(s1.begin());
    print(s1);

    s1.erase(30);
    print(s1);

    s1.clear();
    print(s1);
}

int main() {
    test1();
}