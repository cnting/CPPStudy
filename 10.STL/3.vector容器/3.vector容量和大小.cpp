#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

void print(vector<int> &v) {
    for (auto it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print(v1);

    if (v1.empty()) {
        cout << "v1为空" << endl;
    } else {
        cout << "v1不为空" << endl;
        cout << "v1容量:" << v1.capacity() << endl;
        cout << "v1大小:" << v1.size() << endl;
    }

    //重新指定大小
    v1.resize(20);
    print(v1);

    v1.resize(5);
    print(v1);

}

int main() {
    test1();
}