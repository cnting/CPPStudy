#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void print(int val) {
    cout << val << " ";
}

void test() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), print);
}

int main() {
    test();
}