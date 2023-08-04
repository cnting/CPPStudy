#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

void print(int val) {
    cout << val << " ";
}

void test() {
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), print);
}

int main() {
    test();
}