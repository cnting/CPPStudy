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

    vector<int> v2;
    v2 = v1;
    print(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    print(v3);

    vector<int> v4;
    v4.assign(10,100);
    print(v4);
}

int main() {
    test1();
}