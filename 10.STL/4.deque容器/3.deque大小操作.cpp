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
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    print(d1);

    if (d1.empty()) {
        cout << "d1为空" << endl;
    } else {
        cout << "d1不为空" << endl;
        cout << "d1大小" << d1.size() << endl;
    }

    d1.resize(20);
    cout << "d1大小" << d1.size() << endl;
    d1.resize(5);
    cout << "d1大小" << d1.size() << endl;

}

int main() {
    test1();
}