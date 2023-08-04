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

    deque<int> d2(d1.begin(), d1.end());
    print(d2);

    deque<int> d3(10, 100);
    print(d3);

    deque<int> d4(d3);
    print(d4);
}

int main() {
    test1();
}