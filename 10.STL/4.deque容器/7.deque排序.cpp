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
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    print(d1);

    std::sort(d1.begin(), d1.end());
    print(d1);
}


int main() {
    test1();
}